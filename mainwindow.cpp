#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AgWords.h"
#include <QString>
#include <QListView>
#include <time.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_sizeGen->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
    srand(time(NULL));
    AG::AgWords ag;

    QString solucaoTyped;
    int popTyped, tourTyped, generTyped;
    float mutTyped, crossTyped;

    solucaoTyped = ui->lineEdit_Solution->text();
    popTyped = ui->lineEdit_sizePop->text().toInt();
    tourTyped = ui->lineEdit_sizeTour->text().toInt();
    generTyped = ui->lineEdit_sizeGener->text().toInt();
    mutTyped = ui->lineEdit_probMut->text().toDouble();
    crossTyped = ui->lineEdit_probCross->text().toDouble();

    ag.setSolution(solucaoTyped);
    ag.setPop(popTyped);
    ag.setGen(ag.getSolution().size());
    ag.setTour(tourTyped);
    ag.setGener(generTyped);
    ag.setMut(mutTyped);
    ag.setCros(crossTyped);

    ag.initializationPop();

    for(int i = 0; i < ag.getGener(); i++)
    {
        for(int j = 0; j < ag.getTour(); j++)
        {
            // Calcula a probabilidade de cruzamento
            double prob = ((double) rand() / ((double)RAND_MAX + 1));

            if(prob < ag.getCross())
            {
                // Escolhe dois pais
                int indexFather1 = rand() % ag.getPop();
                int indexFather2;

                // Garante que os índices dos pais não são iguais
                do
                {
                    indexFather2 = rand() % ag.getPop();
                }
                while(indexFather1 == indexFather2);

                vector<char> son;

                // Aplica o cruzamento de 1 ponto
                ag.crossover(indexFather1, indexFather2, son);

                // Calcula a probabilidade de mutação
                prob = ((double) rand() / ((double)RAND_MAX + 1));

                if(prob < ag.getMut())
                    ag.mutation(son);

                int scoreFather = ag.getScores(ag.population[indexFather1]);
                int scoreSon = ag.getScores(son);

                /*
                    Se a pontuação (score) do filho for melhor do
                    que o pai 1, então substitui o pai 1 pelo filho
                */

                if(scoreSon > scoreFather)
                {
                    // Faz a cópia dos genes do filho para o pai
                    for(int k = 0; k < ag.getGen(); k++)
                        ag.population[indexFather1][k] = son[k];
                }
            }
        }

        int bestIndex = ag.getBetter();
        int bestScores = ag.getScores(ag.population[bestIndex]);

        // Exibe resultados no display
        QString saida;
        QCoreApplication::processEvents();
        saida += "   Geracao: " + QString::number(i + 1);
        saida += "\n   Melhor: ";
        for(int j = 0; j < ag.getGen(); j++)
        saida.append(QString(ag.population[bestIndex][j]) + " ");
        saida += "\n   Pontuacao: " + QString::number(bestScores);
        saida += "\n";
        ui->Log->append(saida);

        // Verifica se encontrou a solução digitada no campo Solution
        if(bestScores == ag.getSolution().size())
        break;
   }


}

void MainWindow::on_pushButton_clicked()
{
    ui->Log->clear();
}

