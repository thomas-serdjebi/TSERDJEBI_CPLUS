module;

// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo4;

// On met toutes les classes du module dans un espace de nom pour éviter les conflits
export namespace exo4 {

    // Classe abstraite Shape
    class Shape {
    public:

        virtual double Perimeter() const = 0;


        virtual std::string ToString() const = 0;


        virtual ~Shape() = default;
    };

    // Classe Circle héritant de Shape
    class Circle : public Shape {
    private:
        double rayon;

    public:

        Circle(double rayon) : rayon{rayon} {}

        double Perimeter() const override {
            return 2 * 3.14159 * rayon;
        }

        std::string ToString() const override {
            return std::format("Cercle de rayon: {:.2f}, périmètre: {:.2f}", rayon, Perimeter());
        }
    };


    class Application {
    public:
        Application() {
            std::cout << "Hello from exo4::Application()\n";

            const auto circle = Circle{1.2};
            std::cout << circle.ToString() << std::endl;

            // Test unitaire : vérification du périmètre formaté à 2 décimales
            if (std::format("{0:.2f}", circle.Perimeter()) == "7.54") {
                std::cout << "Test passed: Perimeter is correctly calculated as 7.54" << std::endl;
            } else {
                std::cout << "Test failed: Perimeter calculation mismatch" << std::endl;
            }
        }
    };

}
