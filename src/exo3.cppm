module;

// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo3;

// On met toutes les classes du module dans un espace de nom
export namespace exo3 {

    struct Vector {
        double a{0.0};
        double b{0.0};
        double c{0.0};

        // Constructeur
        Vector(double a, double b, double c) : a{a}, b{b}, c{c} {
            std::cout << "Création d'un Vector: " << ToString() << std::endl;
        }

        // ToString - pour afficher les valeurs du vecteur
        [[nodiscard]] std::string ToString() const {
            return std::format("({:.2f},{:.2f},{:.2f})", a, b, c);
        }

        // Opérateur + (addition de deux vecteurs)
        Vector operator+(const Vector& other) const {
            return Vector{a + other.a, b + other.b, c + other.c};
        }

        // Opérateur * (multiplication scalaire d'un vecteur par un double)
        Vector operator*(double scalar) const {
            return Vector{a * scalar, b * scalar, c * scalar};
        }

        // Opérateur == (vérification d'égalité entre deux vecteurs, défini en tant qu'ami)
        friend bool operator==(const Vector& lhs, const Vector& rhs) {
            return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;
        }
    };

    // Exemple de classe pour tester le fonctionnement de Vector dans main()
    class Application {
    public:
        Application() {
            std::cout << "Hello from exo3::Application()\n";

            const auto vector1 = Vector{1.0, 2.0, 3.0};
            const auto vector2 = Vector{4.0, 5.0, 6.0};

            auto vectorSum = vector1 + vector2;
            std::cout << "vector1 + vector2 = " << vectorSum.ToString() << std::endl;

            auto vectorScaled = vector1 * 2.0;
            std::cout << "vector1 * 2.0 = " << vectorScaled.ToString() << std::endl;


            if (vector1 == vector2) {
                std::cout << "vector1 est égal à vector2\n";
            } else {
                std::cout << "vector1 n'est pas égal à vector2\n";
            }
        }
    };

}
