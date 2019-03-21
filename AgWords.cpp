#include "AgWords.h"
namespace AG {

AgWords::AgWords()
//:sizePop(0), sizeGen(0), sizeTour(0), sizeGener(0), prob_mut(0), prob_cros(0)
{}

//AgWords::AgWords(QString s, int sp, int sg, int to, int ge, double m, double c)
//:solution(s), sizePop(sp), sizeGen(sg), sizeTour(to), sizeGener(ge), prob_mut(m), prob_cross(c)
//{}

void AgWords::initializationPop()
{

    char characters[] = {' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
    'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '#', '$', '%', '&', '-', '?', '_'};



    for(int i = 0; i <= sizePop; i++)
    {
        vector<char> individuo;

        for(int j = 0; j <= sizeGen; j++)
        {
            int num = rand() % 61;
            individuo.push_back(characters[num]);}

        population.push_back(individuo);
    }

}


int AgWords::getBetter()
{
    int bestIndex = 0;
    int bestScores = getScores(population[0]);

    for(int i = 1; i <= sizePop; i++)
    {
        int scores = getScores(population[i]);

        if(scores > bestScores)
        {
            bestIndex = i;
            bestScores = scores;
        }
    }

    return bestIndex;
}

void AgWords::mutation(vector<char>& individuo)
{
    // Escolhe um gene aleatoriamente entre 0 e 61.
    int gene = rand() % sizeGen;

    int n = rand() % 61;
    int n1 = rand() % 61;

    if(individuo[gene] != individuo[n])
        individuo[gene] = individuo[n];

    if(individuo[gene] == individuo[n])
        individuo[gene] = individuo[n1];

}

void AgWords::crossover(int indexFather1, int indexFather2, vector<char>& son)
{
    int spot = rand() % sizeGen;

    for(int i = 0; i <= spot; i++)
        son.push_back(population[indexFather1][i]);

    for(int i = spot + 1; i <= sizeGen; i++)
        son.push_back(population[indexFather2][i]);
}

int AgWords::getScores(vector<char> individuo)
{

        int sizeString = solution.size();

        char repository[1000];

        for(int i = 0; i <= sizeString; i++)
            {
                repository[i] = solution.toStdString()[i];
            }

    int sum = 0;

    for(int i = 0; i < sizeGen; i++)
    {
        if(individuo[i] == repository[i])
        sum += 1;
    }
    return sum;
}


}
