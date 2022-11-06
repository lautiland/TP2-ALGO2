using namespace std;

enum Tipo{
    estandar, //no hace nada
    contaminada,
    envenenada,
    procreadora,
    portal,
    radioactiva
};

enum Estado{
    vivo,
    muerto
};

int ALTO = 5;
int LARGO = 5;
int ANCHO = 5;


class Gen {

	private:
		unsigned int maximoDeCargaGentica;
		unsigned int cargaGentica;

	public:

		/**
		 * pre: maximoDeCargaGentica es un valor 0 o positivo
		 * pos: deja el gen creado con maximoDeCargaGentica en "maximoDeCargaGentica", y cargaGentica en 0.
		 */
		Gen(unsigned int maximoDeCargaGentica);

		/**
		 * pre: maximoDeCargaGentica es un valor 0 o positivo, cargaGentica tiene un valor entre 0 y maximoDeCargaGentica inclusive
		 * pos: deja el gen creado con maximoDeCargaGentica en "maximoDeCargaGentica", y cargaGentica en cargaGentica.
		 */
		Gen(unsigned int maximoDeCargaGentica, unsigned int cargaGentica);

		/**
		 * pre: -
		 * pos: -
		 */
		virtual ~Gen();

		/**
		 * pre: -
		 * pos: devuelve la cargaGentica
		 */
		unsigned int getCargaGentica();

		/**
		 * pre: -
		 * pos: devuelve el maximoDeCargaGentica
		 */
		unsigned int getMaximoDeCargaGentica();

		/**
		 * pre: la cargaGentica debe ser un valor entre 0 y maximoDeCargaGentica inclusive
		 * pos: cambia el valor de cargaGentica
		 */
		void setCargaGentica(unsigned int cargaGentica);

	private:
		/**
		 * pre: -
		 * pos: da error si maximoDeCargaGentica o cargaGentica no respeta los rangos
		 */
		void verificar(unsigned int maximoDeCargaGentica, unsigned int cargaGentica);
};


class AdministradorDeGen {

    private:
        unsigned int maximoDeCargaGentica;

    public:
        /**
         * pre:
         * pos:
         */
        AdministradorDeGen(unsigned int maximoDeCargaGentica);

        /**
         * pre: -
         * pos: -
         */
        virtual ~AdministradorDeGen();

        /**
         * pre: que los genes no sean nulos
         * pos: devuelve un gen con maximoDeCargaGentica en "maximoDeCargaGentica" y cargaGentica como el promedio
         */
        Gen * generar(Gen * gen1, Gen * gen2, Gen * gen3);
};


class Celula{
    private:
        Estado estado;
        Gen gen1;
        Gen gen2;
        Gen gen3;

    public:
        //  Constructores
        Celula();
        Celula(Estado estado);
        Celula(Estado estado, Gen gen1, Gen gen2, Gen gen3);
        //  Getters
        int getGen1();
        int getGen2();
        int getGen3();
        //  Setters
        void setGen1(Gen nuevoGen1);
        void setGen2(Gen nuevoGen2);
        void setGen3(Gen nuevoGen3);
        //  Funciónes
        void mezclarGenes();
};

//calse Celula en cpp:
Celula::celula(){
    this->estado = muerto;
    this->gen1 = 0;
    this->gen2 = 0;
    this->gen3 = 0;

}
//

class Celda{
    private:
        unsigned int posicionX;
        unsigned int posicionY;
        unsigned int posicionZ;
        Tipo tipo;
        Celula celula;
    public:
    //  Constructores
        Celda();
        Celda(Estado estado,int posicionX, int posicionY, int posicionZ, Tipo tipo, Celula celula);
    //  Getters
        Estado getEstado();
    //  Setters
        void setEstado(Estado nuevoEstado);

};

//clase Celda en cpp:

Celda::celda(){
    this->posicionX = 0;
    this->posicionY = 0;
    this->posicionZ = 0;
    this->tipo = estandar;
    this->celula = celula(); 
}

Celda::celda(int posicionX, int posicionY, int posicionZ, Tipo tipo){
    this->posicionX = posicionX;
    this->posicionY = posicionY;
    this->posicionZ = posicionZ;
    this->tipo = estandar;
    this->celula = celula(); 
}

Celda::celda(int posicionX, int posicionY, int posicionZ){
    this->posicionX = posicionX;
    this->posicionY = posicionY;
    this->posicionZ = posicionZ;
    this->tipo = estandar;
    this->celula = celula(); 
}

Celda::celda(int posicionX, int posicionY, int posicionZ, Tipo tipo; Celula celula_new){
    this->posicionX = posicionX;
    this->posicionY = posicionY;
    this->posicionZ = posicionZ;
    this->tipo = estandar;
    this->celula = celula_new; 
}

//
class Malla{
    private:
        Dimenciones espacio;
        Celda p = new matriz[MAXIMO];
        unsigned int cursor;  // 1 2 3 -> 45(?

    public:
        void crearMalla();
        void aniadirCelula(celula newCelula);
        int getCursor();//devuelve resultado
        void setCursor();//calculo

};


class Dimenciones{
    private:
        unsigned int MAXIMO;
        unsigned int ALTO;
        unsigned int LARGO;
        unsigned int ANCHO;

    public:
        Dimenciones();
        int getAncho();
        int getAlto();
        int getLargo();
        void setAncho();
        void setLargo();
        void setAlto();

}

//clase Dimenciones en cpp:

Dimenciones::Dimenciones(){
    this->MAXIMO = 25;
    this->ALTO = 0;
    this->LARGO = 0;
    this->ANCHO = 0;
}

//clase MAlla en cpp:

unsigned int Dimenciones::getAncho(){
    return this->ANCHO;
}

unsigned int Dimenciones::getLargo(){
    return this->LARGO;
}

unsigned int Dimenciones::getAlto(){
    return this->ALTO;
}

void Dimenciones::setAncho(){
    cout << "decime el ancho de la matriz: " << endl;
    cin << this-> ANCHO << endl ;
}

void Dimenciones::setLargo(){
    cout << "decime el largo de la matriz: " << endl;
    cin << this-> LARGO << endl ;}

void Dimenciones::setAlto(){
    cout << "decime el alto de la matriz: " << endl;
    cin << this-> ALTO << endl ;
}


unsigned int Malla::getCursor(){ //devuelve un int xd;
    return this->cursor;
}

void Malla::setCursor(int numero_lista){
    this->cursor = numero_lista;
}

void Malla::setCursor(int x, int y, int z){
    this->cursor = ((z * getAlto() * getLargo()) + (y * getLargo()) + x);
}

void Malla::Malla(){
    setLargo();
    setAncho();
    setAlto();
    for (int pagina = 0; pagina < getAncho(); ++pagina)
    {
        for (int columna = 0; columna < getLargo(); ++columna)
       {
            for (int fila = 0; fila < getAlto(); ++fila)
            {   
                   matriz[ pagina*getAlto()*getLargo + columna*getLargo + fila ] = Celda(fila, columna, pagina);
            }
        }
    }

}




//