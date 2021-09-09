#include <iostream>



class Fraction {
private:
    // Do NOT rename
    int64_t numerator;
    uint64_t denominator;

    // Do NOT delete
    template < class T >
    friend bool operator==(const Fraction& lhs, const T& rhs);

public:
    Fraction() = delete;
    Fraction(const Fraction& rhs):numerator(rhs.getnum()),denominator(rhs.getden()) {
    	//std::cout<<"Copyconst\n";
    };
    Fraction& operator=(const Fraction& rhs){
	   // std::cout<<"operator=\n";
	if(this==&rhs) return *this;
	this->numerator=rhs.getnum();
	this->denominator=rhs.getden();
	return *this;
    }
    Fraction(int64_t numerator, uint64_t denominator){
    		if(numerator==0){
			this->numerator=0;
			this->denominator=1;
		}else{
			int gcd;
			if(numerator<0) gcd=this->gcd(numerator*(-1),denominator);
			else  gcd=this->gcd(numerator,denominator);
			this->numerator=(numerator/gcd);
			this->denominator=(denominator/gcd);
		}
    };
    Fraction(int64_t num){
		
		this->numerator=num;
		this->denominator=1;
		
    }
    int64_t getnum() const{
	return numerator;
    }
    uint64_t getden() const{
	return denominator;
    }
    int gcd(int x,int y){
	return y?gcd(y,x%y):x;
    }
    int nok(int x,int y){
	return x*y/gcd(x,y);
    }
 
    
    //  Add operator overloads below
    Fraction& operator+=(const Fraction& rhs){
	    if(this->numerator==0){
		this->numerator=rhs.getnum();
		this->denominator=rhs.getden();
		return *this;
	    }
	    if(rhs.numerator==0){
		return *this;
	    }
	    int64_t num1=this->getnum();
	    uint64_t den1=this->getden();
	    int64_t num2=rhs.getnum();
	    uint64_t den2=rhs.getden();
	    int nok=this->nok(den1,den2);
	    int nok1=nok/den1;
	    int nok2=nok/den2;
	    num1*=nok1;
	    num2*=nok2;
	    num1+=num2;
	    if(!num1){
		this->numerator=0;
		this->denominator=1;
		return *this;
	    }
	    int gcd;
	    if(num1<0) gcd=this->gcd(num1*(-1),nok);//Find GCD to simplify Fraction
	    else gcd=this->gcd(num1,nok);
	    num1/=gcd;
	    nok/=gcd;
	    this->numerator=num1;
	    this->denominator=nok;
	    return *this;
		
    }
    Fraction operator+(const Fraction& rhs)const{
	    Fraction y=*this;
	    return y+=rhs;
    }
    Fraction& operator-=(const Fraction& rhs){
	    if(this->numerator==0){
		this->numerator-=rhs.getnum();
		this->denominator=rhs.getden();
		return *this;
	    }
	    if(rhs.numerator==0){
		return *this;
	    }
	   int64_t num1=this->getnum();
	    uint64_t den1=this->getden();
	    int64_t num2=rhs.getnum();
	    uint64_t den2=rhs.getden();
	    int nok=this->nok(den1,den2);
	    int nok1=nok/den1;
	    int nok2=nok/den2;
	    num1*=nok1;
	    num2*=nok2;
	    num1-=num2;
	    if(!num1){
		this->numerator=0;
		this->denominator=1;
		return *this;
	    }
	    int gcd;
	    if(num1<0) gcd=this->gcd(num1*(-1),nok);//Find GCD to simplify Fraction
	    else gcd=this->gcd(num1,nok);
	    num1/=gcd;
	    nok/=gcd;
	    this->numerator=num1;
	    this->denominator=nok;
	    return *this;
    }
    Fraction operator-(const Fraction& rhs) const {
	Fraction y=*this;
	return y-=rhs;
    }
    Fraction operator-() const{
	return Fraction(-numerator,denominator);
    }
    Fraction& operator*=(const Fraction& rhs){
	    if(this->numerator==0){
		    return *this;
	    }
	    if(rhs.numerator==0){
		this->numerator=0;
		this->denominator=1;
	 	return *this;
	    }
	    int64_t num1=this->getnum();
	    uint64_t den1=this->getden();
	    int64_t num2=rhs.numerator;
	    uint64_t den2=rhs.denominator;
	    //std::cout<<num1<<"/"<<den1<<" "<<num2<<"/"<<den2<<'\n';
	    num1*=num2;
	    den1*=den2;
	   // std::cout<<num1<<"/"<<den1;
	   int gcd;
	   if(num1<0) gcd=this->gcd(num1*(-1),den1);//Find GCD to simplify Fraction
	   else gcd=this->gcd(num1,den1);
	    num1/=gcd;
	    den1/=gcd;
	    this->numerator=num1;
	    this->denominator=den1;
	    return *this;
	
    }
    Fraction operator*(const Fraction& rhs)const{
	Fraction y=*this;
	return y*=rhs;	
    }
};
std::ostream& operator<<(std::ostream& out,Fraction& frac){
return out<<frac.getnum()<<"/"<<frac.getden()<<'\n';
}

int main(){
	Fraction f(2,18);
	std::cout<<f;
	Fraction sum(1);
	sum+=f;
	std::cout<<sum;
	/*Fraction f2(12,18);
	std::cout<<f2;
	f2*=f;
	std::cout<<f2;*/
	return 0;
}
