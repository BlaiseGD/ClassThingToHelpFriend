#include <bits/stdc++.h>
using namespace std;

vector<string> itemsName;
vector<double> itemsCost;


class cart{
  //private by default so you can declare vars at the top and not worry about it
  const double tax = 1.0975;
  double cost;
  public:
    cart(string item){
      //cout << "I am a constructor";
    cout << "Added: " + item << endl;
    itemsName.push_back(item);
    }
    void setCost(double price){
      cost = price;
      cout << "Item Costs: " + to_string(cost) << endl;
      itemsCost.push_back(cost * tax);
    }
    double getCost(){
      return cost * tax;
    }
};


int main() {
  double itemPrice, grandTotal;
  string itemName,continueShop;
  bool shopping = true;
  cout << "Do you want to add items to the cart?" << endl;
  cin >> continueShop;
  if(continueShop == "no") return 0;
  while(shopping){
    cout << "What is the item and cost?" << endl;
    cin >> itemName >> itemPrice;
    cart tmpItem = cart(itemName);
    tmpItem.setCost(itemPrice);
    grandTotal += tmpItem.getCost();
    cout << "Total: " + to_string(grandTotal) << endl << endl;
    cout << "Would you still like to shop? ";
    cin >> continueShop;
    system("clear");
    shopping = (continueShop == "no")?false:true;
  }
  cout << "\u001b[36mItems in cart\u001b[33m" << endl;
  for(int i = 0; i < itemsName.size(); i++){
    cout << itemsName[i] << " - $"<< itemsCost[i] << endl;
  }
  
  cout << endl << endl << "\u001b[37mGrandtotal is \u001b[33m$" + to_string(grandTotal);
  return 0;
} 
