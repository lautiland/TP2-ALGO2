enum Tipo{
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

class Celda{
    private:
        Estado estado;
        int posicionX;
        int posicionY;
        int posicionZ;
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

class Malla{
    private:
        Celda matriz[125];
        int cursor;

    public:

};