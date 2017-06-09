#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>
#include "typedef.h"
#include <QPlainTextEdit>
#include "myhighlighter.h"
class Editor : public QPlainTextEdit
{
	Q_OBJECT

public:
	Editor(QWidget *parent = 0);
	void newFile();
	bool loadFile(const QString &fileName);
	bool save();
	bool saveAs();
	bool saveFile(const QString &fileName);
	QString userFriendlyCurrentFile();
	QString currentFile() { return curFile; }

	void setMode(editorMode mode);
	void lineNumberAreaPaintEvent(QPaintEvent *event);
	int lineNumberAreaWidth();
protected:
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
	void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
	private slots:
	void documentWasModified();
	void updateLineNumberAreaWidth(int newBlockCount);
	void highlightCurrentLine();
	void updateLineNumberArea(const QRect &, int);
private:
	bool maybeSave();
	void setCurrentFile(const QString &fileName);
	QString strippedName(const QString &fullFileName);
	QWidget *lineNumberArea;
	QString curFile;
	bool isUntitled;
};
//ÐÐºÅ
class LineNumberArea : public QWidget
{
public:
	LineNumberArea(Editor *editor) : QWidget(editor) {
		codeEditor = editor;
	}

	QSize sizeHint() const Q_DECL_OVERRIDE {
		return QSize(codeEditor->lineNumberAreaWidth(), 0);
	}

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE {
		codeEditor->lineNumberAreaPaintEvent(event);
	}

private:
	Editor *codeEditor;
};
#endif