 #include <iostream>
 #include <vector>
 #include <math.h>
 #include <string>
 #include <string.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double Ti01=460;
    double Ti02=360;
    double Wi1=100;
    double Wi2=150;
    double Tj01=350;
    double Tj02=300;
    double Tjav1=400;
    double Tjav2=340;
    double Wj1=200;
    double Wj2=150;
    double qj1=10000;
    double qj2=6000;
    double q_=Wj1*(Tjav1-Tj01)+Wj2*(Tjav2-Tj02);
    double Tav=(Wi1*Ti01+Wi2*Ti02-q_)/(Wi1+Wi2);
    double sigma0=Wi1*(log(Tav/Ti01))+Wi2*(log(Tav/Ti02))
    +Wj1*(log(Tjav1/Tj01))+Wj2*(log(Tjav2/Tj02));
    double W2=Wi1+Wi2;
    double A1=(Wj1-Wi1)/(Wi1*Wj1);
    double K1=(1/A1)*log((Ti01-Tjav1)/(Ti02-Tj01));
    double A2=(Wj2-W2)/(Wj2*W2);
    double K2=(1/A2)*log((Ti02-Tjav2)/(Tav-Tj02));
    double K=K1+K2;
    double m=1-(1/K)*(Wi1*log(Ti01/Tav)+Wi2*log(Ti02/Tav));
    double sigma=K*(pow(1-m,2))/m;
    double nu=sigma/sigma0;
    double W21=Wi2*(Wi1/(Wi1+Wi2));
    double W22=Wi2*(Wi2/(Wi1+Wi2));
    cout<<"Потребная теплота:"<<q_<<" Вт"<<endl;
    cout<<"Температура горячих потоков на выходе:"<<Tav<<" K"<<endl;
    cout<<"Производство энтропии:"<<sigma0<<" Вт/K"<<endl;
    cout<<"Коэффициент теплообмена первого интервала:"<<K1<<" Вт/K"<<endl;
    cout<<"Коэффициент теплообмена второго интервала:"<<K2<<" Вт/K"<<endl;
    cout<<"Суммарный коээфициент теплообмена:"<<K<<" Вт/K"<<endl;
    cout<<"Минимально возможное производство энтропии:"<<sigma<<" Вт/K"<<endl;
    cout<<"W21:"<<W21<<" Вт/K\n"<<"W22:"<<W22<<" Вт/K";

}
