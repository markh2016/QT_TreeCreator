#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QTextStream>
#include <QImage>
#include <QPainter>
#include <QFont>
#include <QThread>
#include <QInputDialog>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFile>

class TreeCreator
{
public:

 // enum  gives index into color array in function  static void typewriterPrint
    enum ForeColor
    {
        ForeRed,
        ForeYellow,
        ForeGreen,
        ForeCyan,
        ForeWhite
    };

    static QString listFiles(const QString &folderPath, QString indent = "", QFile *file = nullptr)
    {
        QString outputText;
        QDir dir(folderPath);
        QFileInfoList entries = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

        for (const QFileInfo &entry : entries)
        {
            QString itemPath = entry.filePath();
            QString itemName = entry.fileName();
            if (entry.isDir())
            {
                outputText += (indent + "|-- " + itemName + "/\n");
                typewriterPrint(indent + "|-- " + itemName + "/\n", ForeYellow, 0.04, stdout);
                if (file)
                    file->write((indent + "|-- " + itemName + "/\n").toUtf8());
                outputText += listFiles(itemPath, indent + "    ", file);
            }
            else
            {
                outputText += (indent + "|-- " + itemName + "\n");
                typewriterPrint(indent + "|-- " + itemName + "\n", ForeRed, 0.04, stdout);
                if (file)
                    file->write((indent + "|-- " + itemName + "\n").toUtf8());
            }
        }
        return outputText;
    }

    static void generateTree(int argc, char *argv[])
    {
        QApplication app(argc, argv); // Create QApplication instance

        QString folderName = QInputDialog::getText(nullptr, "Folder Name", "Enter a folder name:");

        qDebug() << "You entered: " << folderName;

        // Search for the folder in the user's home area
        QString homeDirectory = QDir::homePath();
        QString folderPath;
        QDirIterator it(homeDirectory, QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
        while (it.hasNext())
        {
            it.next();
            if (it.fileName() == folderName)
            {
                folderPath = it.filePath();
                break;
            }
        }

        // Verify if the folder exists
        if (folderPath.isEmpty())
        {
            qDebug() << "Folder not found.";
            return;
        }

        // Change to the directory
        QDir::setCurrent(folderPath);

        // Save folder structure to file
        QString outputFilename = "Project_Tree.txt";
        QFile outputFile(outputFilename);
        if (outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            outputFile.write("Folder Structure:\n");
            QString outputText = listFiles(folderPath, "", &outputFile);

            outputFile.close(); // Close the file after writing
            createImage(outputText, "folder_structure.png");
            displayImage("folder_structure.png");
        }
        else
        {
            qDebug() << "Failed to open the output file.";
            return;
        }

        // Print folder structure saved message
        typewriterPrint("Folder structure saved to: \n ", ForeGreen, 0.04, stdout);
        typewriterPrint(QDir::toNativeSeparators(QDir::currentPath()) + "/" + outputFilename +"\n", ForeCyan, 0.04, stdout);
    }

private:
    static void typewriterPrint(const QString &text, ForeColor color, double delay, FILE *stream)
    {
        static const QString colors[] = {QString("\033[31m"), QString("\033[33m"), QString("\033[32m"), QString("\033[36m"), QString("\033[0m")};
        QTextStream out(stream);
        for (const QChar &ch : text)
        {
            out << colors[color] << ch;
            out.flush();
            QThread::msleep(static_cast<int>(delay * 1000));
        }
        // Reset text color to default
        out << colors[ForeWhite];
    }

    static void createImage(const QString &text, const QString &outputFilename)
    {
        int fontSize = 12; // Updated font size
        int lineSpacing = 1 ;
        QString fontPath = "/usr/share/fonts/truetype/lato/Lato-Medium.ttf";

        QImage sampleImage(1, 1, QImage::Format_RGB32);
        QPainter samplePainter(&sampleImage);
        QFont font(fontPath, fontSize);

        QFontMetrics fontMetrics(font);
        int line_height = fontMetrics.height() + lineSpacing;
        int max_line_width = 0;
        QStringList lines = text.split('\n');
        for (const QString &line : lines)
        {
            int line_width = fontMetrics.horizontalAdvance(line);
            if (line_width > max_line_width)
                max_line_width = line_width;
        }

        int imageWidth = max_line_width + 20;
        int imageHeight = line_height * lines.size() + 20;
        QImage image(imageWidth, imageHeight, QImage::Format_RGB32);
        image.fill(Qt::white);
        QPainter painter(&image);

        int y = 10;
        for (const QString &line : lines)
        {
            painter.drawText(10, y, line);
            y += line_height;
        }

        image.save(outputFilename);
    }

    static void displayImage(const QString &imageFilename)
    {
        QImage image(imageFilename);
        if (image.isNull())
        {
            qDebug() << "Failed to load the image: " << imageFilename;
            return;
        }

        QGraphicsScene scene;
        QGraphicsView view(&scene);
        QGraphicsPixmapItem item(QPixmap::fromImage(image));
        scene.addItem(&item);
        view.setWindowTitle("TreeView By MD Harrington QT Console Application");
        view.show();

        QApplication::exec();
    }
};

int main(int argc, char *argv[])
{
    TreeCreator::generateTree(argc, argv);

    return 0;
}
