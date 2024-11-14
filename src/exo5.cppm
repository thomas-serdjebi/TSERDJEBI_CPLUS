module;

// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo5;

// On met toutes les classes du module dans un espace de nom pour éviter les conflits
export namespace exo5 {

    // Classe abstraite Shape
    class Shape {
    public:

        virtual double Perimeter() const = 0;


        virtual std::string ToString() const = 0;


        virtual ~Shape() = default;
    };


    class Circle : public Shape {
    private:
        double rayon;

    public:

        Circle(double rayon) : rayon{rayon} {}

        double Perimeter() const override {
            return 2 * std::numbers::pi * rayon;
        }

        std::string ToString() const override {
            return std::format("Cercle de rayon: {:.2f}, périmètre: {:.2f}", rayon, Perimeter());
        }
    };


    class Polygon : public Shape {
    private:
        std::vector<double> cotes;

    public:

        Polygon(std::initializer_list<double> cotes) : cotes{cotes} {}

        double Perimeter() const override {
          return std::accumulate(cotes.begin(), cotes.end(), 0.0);
        }
        std::string ToString() const override {
            return std::format("Polygone avec {} côtés, périmètre: {:.2f}", cotes.size(), Perimeter());
        }
    };

    class Rectangle : public Polygon {
    private:
        double height;
        double width;

    public:

        Rectangle(double hauteur, double largeur)
            : Polygon{hauteur, largeur, largeur, hauteur}, height{hauteur}, width{largeur} {}

        std::string ToString() const override {
            return std::format("Rectangle ({} x {}), périmètre: {:.2f}", height, width, Perimeter());
        }
    };

    class Square : public Rectangle {
    private:
        double side;

    public:

        Square(double cote) : Rectangle{cote, cote}, side{cote} {}

        std::string ToString() const override {
            return std::format("Square ({} x {}), périmètre: {:.2f}", side, side, Perimeter());
        }
    };



    class Application {
    public:
        Application() {
            std::cout << "Hello from exo5::Application()\n";
        }
    };

}
