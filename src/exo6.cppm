module;


// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo6;

// On met toutes les classes du module dans un espace de nom pour éviter les conflits
export namespace exo6 {
  class VectorUtils   {

  public:
    static void Print(const std::vector<int> &vec) {
      for_each(vec.begin(), vec.end(), [](int i) {
        std::cout << i << " ";
      });
    }

    static void SortAndRemoveDuplicates(std::vector<int> &vec) {
      std::sort(vec.begin(), vec.end());
      vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    }

    static int CountGreatersThan(const std::vector<int> &vec, int threshold) {
      const int counter = std::count_if(vec.begin(), vec.end(), [&threshold](const int i) {
        return i > threshold ;
      });

      return counter;
    };

    class Application {
    public:
      Application() {
        std::cout << "Hello from exo6::Application()\n";
      }
    };

  };
}
