#include<iostream>
#include<string>
#include<vector> //Equivalente a ArrayList<...> en Java

/* BookStore
* Este es un programa donde el usuario puede ingresar cuantos libros quiera el usuario, pide 3 cosas: Codigo, 
* Cantidad y Precio. Al final se contabilizará la cantidad de libros con el mismo código.
*/

using namespace std;

class Sales_item{
	
	private:
		string code;
		int amount;
		float price;

	public: 
	
		// Setter Price
		void setPrice(float price){
			this->price = price;
		}
	
		// Vamos a hacer una sobrecargar de operadores: Class1 + Class2 = Class3
		Sales_item operator + (Sales_item otro){
			Sales_item new_class;
			//Vamos a sumar las clases siempre y cuando tengan el mismo código
			if(*this == otro){
				new_class.code = this->code;
				new_class.amount = this->amount + otro.amount;
				new_class.price = this->price;
			} else{
				cout<<"No es posible sumar libros distintos"<<endl;
			}
			return new_class;
		}
		
		// Sobrecargar el operador de igualdad
		bool operator == (Sales_item& otro){
			return this->code == otro.code;
		}
		
		// Operador de imprimir en pantalla un objeto
		friend ostream& operator << (ostream& cout, Sales_item& obj){
			cout <<"Codigo: "<<obj.code<<" | Cantidad: "<<obj.amount<<" | Precio: "<<obj.price;
			return cout;
		}
		
		// Operador de ingresar datos de un objeto
		friend istream& operator >> (istream& cin, Sales_item& obj){
			cout<<"\nEnter a book "<<endl;
			cout<<"Codigo: "; cin>>obj.code;
			cout<<"Cantidad: "; cin>>obj.amount;
			
			return cin;
					
		}
		
		// Idea: Crear una función que me retorne true si hay ingreso un libro con código ya existente
		// Con el '&' paso mi lista por referencia, es decir cualquier cambio aquí afectará a la original
		bool repeatCode(vector<Sales_item>& lista, Sales_item& item){
			
			// Lo que vamos a hacer ahora es comparar el elemento recién ingresado con la lista
			for(int i = 0; i<lista.size(); i++){
				// Comparamos con el siguiente en adelante
				if(lista[i] == item){
					// Antes de devolver true quiero fusionar los 2 objetos iguales y añadir uno nuevo
					// También eliminar los repetidos
					Sales_item new_item;
					new_item = lista[i] + item;
					lista.erase(lista.begin() + i);
					lista.push_back(new_item);
					return true;
				} 
			}
			// En caso de revisar todo y no se encuentran coincidencias
			return false;
		}
		
		friend void presentarResultados(vector<Sales_item>& lista){
			cout<<"\n\n.:INVENTARIO FINAL:."<<endl;
			
			for(int i = 0; i<lista.size(); i++){
				cout<<"["<<i+1<<"] "<<lista[i]<<endl;
			}

		}
		
};

int main(){
	
	cout<<"Ingrese cntrl + Z si desea detener el ingreso"<<endl;
	
	cout<<"\nCódigo: Puede ser un numero o una letra '1', '2', 'a'"<<endl;
	cout<<"Al final se contabilizaran todos los libros con el mismo codigo"<<endl;
	
	vector<Sales_item> listaItems;
	Sales_item item;
	float price;
	
	while(cin>>item){
		/* MEJORA: Si encontramos 2 códigos repetidos, debemos sumarlos
		* Eliminar los 2 elementos por separado
		* Ingresar la suma de los 2 elementos a la lista
		* Básicamente vamos a estar haciendo fusiones */
		if(!item.repeatCode(listaItems, item)){
			cout<<"Precio: "; cin>>price;
			item.setPrice(price);
			listaItems.push_back(item);
		}
	}
	
	presentarResultados(listaItems);


	return 0;
}