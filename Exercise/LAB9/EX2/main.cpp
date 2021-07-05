#include "sales.h"
double arr[4] = {345.2,621.8,1073.5,0};

int main() {
    using namespace SALES;
    Sales s;
    
    setSales(s,arr,3);
    showSales(s);
    setSales(s);
    showSales(s);
}