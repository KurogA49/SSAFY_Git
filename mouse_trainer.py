from PySide6.QtWidgets import *
from PySide6.QtCore import *
from default import Ui_Form
import random

class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()
        self.cycle = 1000
        self.count = 0

    def changeColor(self):
        color = QColorDialog.getColor()
        if color.isValid():
            self.label.setStyleSheet(f"background-color:{color.name()}")

    def changeName(self):
        name, ok = QInputDialog.getText(self, "Input", "What is your name?")
        if ok:
            self.label.setText(name)

    def showDiagram(self):
        sender = self.sender()
        if sender.text() == "이름 변경":
            self.changeName()
        else:
            self.changeColor()

    def mousePressEvent(self, e):
        x = e.x()
        y = e.y()

        tx = self.label.x()
        ty = self.label.y()

        if tx <= x <= tx + self.label.width() and ty <= y <= ty + self.label.height():
            self.count += 1
            if self.cycle >= 310:
                self.cycle -= 30
                self.timer.start(self.cycle, self)
            msg = QMessageBox()
            msg.setText(f"Success\nTotal:{self.count}")
            msg.exec()

    def resetCount(self):
        self.count = 0
        self.cycle = 1000
        self.timer.start(self.cycle, self)

    def timerEvent(self, e):
        x = random.randint(0, self.frame.size().width() - self.label.width())
        y = random.randint(0, self.frame.size().height() - self.label.height())
        self.label.move(x, y)

    def main(self):
        self.timer = QBasicTimer()
        self.timer.start(1000, self)


app = QApplication()
main = MyApp()

main.show()
app.exec()