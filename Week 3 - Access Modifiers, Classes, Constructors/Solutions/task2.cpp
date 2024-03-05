#include <iostream>
#include <cstring>

class Tourist
{
    private:
        char name[31];
        char city[31];
        char plate[9];
        double stressCoeficient;
        char krustovishte[31];

    public: 
        Tourist();
        Tourist(char*, char*, char*, double, char*);
        void timeToFree() const;
};

Tourist::Tourist()
{
    strcpy(name, "Ivan");
    strcpy(city, "Sofia");
    strcpy(plate, "CA8713KA");
    stressCoeficient = 6;
    strcpy(krustovishte, "Bulgaria-Gabrovski");
}
Tourist::Tourist(char* _name, char* _city, char* _plate, double _stressCoeficient, char* _krustovishte)
{
    if(strlen(_name) > 30 || strlen(_city) > 30 || strlen(_plate) > 8 || strlen(_krustovishte) > 30)
    {
        Tourist();
    }
    else
    {
        strcpy(name, _name);
        strcpy(city, _city);
        strcpy(plate, _plate);
        stressCoeficient = _stressCoeficient;
        strcpy(krustovishte, _krustovishte);
    }
}
void Tourist::timeToFree() const
{
    double time = 0.8 * stressCoeficient;
    if(plate[0] != 'B' || plate[1] != 'T')
    {
        time += 4;
    }
    std::cout << krustovishte << " " << time << std::endl;
}

