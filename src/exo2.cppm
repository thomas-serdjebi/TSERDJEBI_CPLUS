module;
// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo2;

// On met toutes les classes du module dans un espace de nom
// ayant le même nom que le module pour plus de clarté et éviter
// les conflits de nommage.
// On exporte la totalité des classe de l'espace de nom.
export namespace exo2 {

    class Vector {
    private:
        double a{0.0};
        double b{0.0};
        double c{0.0};

    public:
        Vector(const double a, const double b, const double c) : a(a), b(b), c(c) {
            std::cout << "Création objet Vector " << a << "-" << b << "-" << c << std::endl;
        }

        Vector(const Vector& other) : a(other.a), b(other.b), c(other.c) {
            std::cout << "Vector copié\n" << a << "-" << b << "-" << c << std::endl;
        }

        // ACCESSEURS => NODISCARD pour avertir si retour non utilisée
        [[nodiscard]] double GetA() { return a; }
        [[nodiscard]] double GetB() { return b; }
        [[nodiscard]] double GetC() { return c; }

        // MODIFICATEURS => void car les fonctions de retournent pas les valeurs
        void SetA(const double newA) { a = newA; }
        void SetB(const double newB) { b = newB; }
        void SetC(const double newC) { c = newC; }

        void Homothety(double multiplicateur) {
            a *= multiplicateur;
            b *= multiplicateur;
            c *= multiplicateur;
        }

        void Sum1(Vector autre) {
            a += autre.a;
            b += autre.b;
            c += autre.c;
        }

        void Sum2(const Vector &autre) {
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
            std::cout << "Hello from exo2::Application()\n";

            const auto vector1 = Vector{1.0, 2.0, 3.0};
            std::cout << "Initial Vector 1: " << vector1.ToString() << std::endl;

            auto vector2 = Vector{4.0, 5.0, 6.0};
            std::cout << "Initial Vector 2: " << vector2.ToString() << std::endl;

            // Utilisation de Homothety
            //vector2.Homothety(2.0);
            //std::cout << "Vector 2 after homothety by 2.0: " << vector2.ToString() << std::endl;

            // Utilisation de Sum1 (passage par copie)
            vector2.Sum1(vector1);
            std::cout << "Vector 2 after Sum1 with Vector 1: " << vector2.ToString() << std::endl;

            // Utilisation de Sum2 (passage par référence)
            vector2.Sum2(vector1);
            std::cout << "Vector 2 after Sum2 with Vector 1: " << vector2.ToString() << std::endl;
        }
    };

}