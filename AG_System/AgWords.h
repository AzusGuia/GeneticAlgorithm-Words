#ifndef AGWORDS_H
#define AGWORDS_H
#include <vector>
#include <QString>

using namespace std;

namespace AG {

    class AgWords
    {

    private:

        QString solution;
        int sizePop;
        int sizeGen;
        int sizeTour;
        int sizeGener;
        double prob_mut;
        double prob_cross;

    public:

        AgWords();
        //AgWords(QString solution, int sp, int sg, int to, int ge, double m, double c);
        std::vector<std::vector<char>> population;


        // Sets
        void setPop(int p){sizePop = p;}
        void setGen(int g){sizeGen = g;}
        void setTour(int t){sizeTour = t;}
        void setGener(int ge){sizeGener = ge;}
        void setMut(double m){prob_mut = m;}
        void setCros(double c){prob_cross = c;}
        void setSolution(QString s){solution = s;}

        // Gets
        int getPop(){return sizePop;}
        int getGen(){return sizeGen;}
        int getTour(){return sizeTour;}
        int getGener(){return sizeGener;}
        double getMut(){return prob_mut;}
        double getCross(){return prob_cross;}
        QString getSolution(){return solution;}

        // Metodos
        void initializationPop();
        int getBetter();
        void mutation(vector<char>& individuo);
        void crossover(int indexFather1, int indexFather2, vector<char>& son);
        int getScores(vector<char> individuo);

//Initialization


    }; //End Class AgWords

} //End namesoace AlgGen

#endif // AGWORDS_H
