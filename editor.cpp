#include "editor.h"
#include <QtWidgets>


Editor::Editor(QWidget *parent) : QPlainTextEdit(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	isUntitled = true;

	lineNumberArea = new LineNumberArea(this);

	connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
	connect(this, SIGNAL(updateRequest(QRect, int)), this, SLOT(updateLineNumberArea(QRect, int)));
	connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
	QFont *font = new QFont();//"MicrosoftYaHei"
	font->setFamily(QStringLiteral("微软雅黑"));
	font->setPointSize(12);
	this->setFont(*font);
	updateLineNumberAreaWidth(0);
	//setMode(BROWSE);
	this->setStyleSheet("background:#f2f2f3;");
	highlightCurrentLine();

	setMode(EDIT);
	MyHighLighter *highlighter = new MyHighLighter(this->document());
}


//新建文件
void Editor::newFile()
{
	static int sequenceNumber = 1;

	isUntitled = true;
	curFile = tr("document%1.txt").arg(sequenceNumber++);
	setWindowTitle(curFile + "[*]");

	connect(document(), &QTextDocument::contentsChanged,
		this, &Editor::documentWasModified);
}
//加载文件
bool Editor::loadFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("MDI"),
			tr("Cannot read file %1:\n%2.")
			.arg(fileName)
			.arg(file.errorString()));
		return false;
	}

	QTextStream in(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	setPlainText(in.readAll());
	QApplication::restoreOverrideCursor();

	setCurrentFile(fileName);

	connect(document(), &QTextDocument::contentsChanged,
		this, &Editor::documentWasModified);

	return true;
}
//保存
bool Editor::save()
{
	if (isUntitled) {
		return saveAs();
	}
	else {
		return saveFile(curFile);
	}
}
//另存为
bool Editor::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
		curFile);
	if (fileName.isEmpty())
		return false;

	return saveFile(fileName);
}

bool Editor::saveFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("MDI"),
			tr("Cannot write file %1:\n%2.")
			.arg(QDir::toNativeSeparators(fileName), file.errorString()));
		return false;
	}

	QTextStream out(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	out << toPlainText();
	QApplication::restoreOverrideCursor();

	setCurrentFile(fileName);
	return true;
}

QString Editor::userFriendlyCurrentFile()
{
	return strippedName(curFile);
}
//设置编辑器的模式
void Editor::setMode(editorMode mode)
{
	if (mode == BROWSE)
	{
		this->setReadOnly(true);
		this->setStyleSheet("background:#f2f2f3;");
		highlightCurrentLine();
	}
	else if (mode == EDIT)
	{
		this->setReadOnly(false);
		this->setStyleSheet("background:#ffffff;");
		highlightCurrentLine();
	}
}
//行号绘制事件
void Editor::lineNumberAreaPaintEvent(QPaintEvent * event)
{
	QPainter painter(lineNumberArea);
	painter.fillRect(event->rect(), Qt::lightGray);


	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = (int)blockBoundingGeometry(block).translated(contentOffset()).top();
	int bottom = top + (int)blockBoundingRect(block).height();

	while (block.isValid() && top <= event->rect().bottom()) {
		if (block.isVisible() && bottom >= event->rect().top()) {
			QString number = QString::number(blockNumber + 1);
			painter.setPen(Qt::black);
			painter.drawText(-2, top, lineNumberArea->width(), fontMetrics().height(),
				Qt::AlignRight, number);
		}

		block = block.next();
		top = bottom;
		bottom = top + (int)blockBoundingRect(block).height();
		++blockNumber;
	}
}
//行号区域宽度
int Editor::lineNumberAreaWidth()
{
	int digits = 1;
	int max = qMax(1, blockCount());
	while (max >= 10) {
		max /= 10;
		++digits;
	}

	int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

	return space;
}

void Editor::closeEvent(QCloseEvent *event)
{
	if (maybeSave()) {
		event->accept();
	}
	else {
		event->ignore();
	}
}

void Editor::documentWasModified()
{
	setWindowModified(document()->isModified());
}
//更新行号区域宽度
void Editor::updateLineNumberAreaWidth(int /*newBlockCount*/)
{
	setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}
//将当前行高亮
void Editor::highlightCurrentLine()
{
	QList<QTextEdit::ExtraSelection> extraSelections;

	if (!isReadOnly()) {
		QTextEdit::ExtraSelection selection;

		QColor lineColor = QColor(Qt::yellow).lighter(160);

		selection.format.setBackground(lineColor);
		selection.format.setProperty(QTextFormat::FullWidthSelection, true);
		//selection.cursor = textCursor();
		//selection.cursor.clearSelection();
		extraSelections.append(selection);
	}

	setExtraSelections(extraSelections);
}
//更新行号区域
void Editor::updateLineNumberArea(const QRect &rect, int dy)
{
	if (dy)
		lineNumberArea->scroll(0, dy);
	else
		lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

	if (rect.contains(viewport()->rect()))
		updateLineNumberAreaWidth(0);
}

bool Editor::maybeSave()
{
	if (!document()->isModified())
		return true;
	const QMessageBox::StandardButton ret
		= QMessageBox::warning(this, tr("MDI"),
			tr("'%1' has been modified.\n"
				"Do you want to save your changes?")
			.arg(userFriendlyCurrentFile()),
			QMessageBox::Save | QMessageBox::Discard
			| QMessageBox::Cancel);
	switch (ret) {
	case QMessageBox::Save:
		return save();
	case QMessageBox::Cancel:
		return false;
	default:
		break;
	}
	return true;
}

void Editor::setCurrentFile(const QString &fileName)
{
	curFile = QFileInfo(fileName).canonicalFilePath();
	isUntitled = false;
	document()->setModified(false);
	setWindowModified(false);
	setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QString Editor::strippedName(const QString &fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}
//调整大小事件
void Editor::resizeEvent(QResizeEvent *e)
{
	QPlainTextEdit::resizeEvent(e);

	QRect cr = contentsRect();
	lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}