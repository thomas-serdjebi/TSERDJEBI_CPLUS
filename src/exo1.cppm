module;
// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo1;

// On met toutes les classes du module dans un espace de nom
// ayant le même nom que le module pour plus de clarté et éviter
// les conflits de nommage.
// On exporte la totalité des classe de l'espace de nom.
export namespace exo1 {

    // Exemple de classe pour convention de nommage

    class Vector {
    private:
        double a{0.0};
        double b{0.0};
        double c{0.0};
    public:

        Vector(const double a, const double b, const double c) : a(a), b(b), c(c) {}

        //ACCESSEURS => NODISCARD  pour avertir si retour non utilisée
        [[nodiscard]] double GetA() { return a; }
        [[nodiscard]] double GetB() { return b; }
        [[nodiscard]] double GetC() { return c; }

        //MODIFICATEURS => void car les fonctions de retournent pas les valeurs
        //VOID indique qu'on modifie directement l'objet
        void  SetA(const double newA) { a = newA ;} ;
        void  SetB(const double newB) { b = newB ;} ;
        void  SetC(const double newC) { c = newC ;} ;

        void Homothety(double multiplicateur) {
            a *= multiplicateur;
            b *= multiplicateur;
            c *= multiplicateur;
        }

        void Sum(const Vector &autre) {
            a += autre.a;
            b += autre.b;
            c += autre.c;
        }

        [[nodiscard]] std::string ToString() const {
            return std::format("({:.2f},{:.2f},{:.2f})", a, b, c);
        }


    };


    // Exemple de classe utilisée dans la fonction main()
    class Application {
    public:
        // Tout le code de l'exercice doit être dans ce constructeur
        Application() {
            //std::cout << "Hello from exo1::Application()\n";
           // const auto vector1 = Vector{1.0, 2.0, 3.0};
           // std::cout << "Initial Vector 1: " << vector1.ToString() << std::endl;

            //auto vector2 = Vector{4.0, 5.0, 6.0};
           // std::cout << "Initial Vector 2: " << vector2.ToString() << std::endl;

            // Appliquer une homothétie
           // vector2.Homothety(2.0);
           // std::cout << "Vector 2 after homothety by 2.0: " << vector2.ToString() << std::endl;

            // Additionner les composantes de vector1 à vector2
            //vector2.Sum(vector1);
            //std::cout << "Vector 2 after adding Vector 1: " << vector2.ToString() << std::endl;
        }
    };

}