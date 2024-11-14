module;


// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo7;

// On met toutes les classes du module dans un espace de nom pour éviter les conflits
export namespace exo7 {

  class Resource {
  public:

    //On définit le constructeur qui doit afficher le message
    Resource() {
      std::cout << "Création objet resource"  << std::endl;
    }

    ~Resource() {
      std::cout << "Destruction de l'objet resource"  << std::endl;
    }

    void DoSomething() {
      std::cout << "Resource fait quelque chose."  << std::endl;
    }
  };

    class Application {
    public:
      Application() {
        std::cout << "Hello from exo6::Application()\n"  << std::endl;
        UniquePtr();
        SharedPtr();
      }

      void UniquePtr() {
        auto Ressource = std::make_unique<Resource>();
        Ressource->DoSomething();
      }

      void UseSharedPtr(const std::shared_ptr<Resource> res) {
          std::cout << "Compteur de res " << res.use_count() << std::endl;
          res->DoSomething();
          if (res.use_count() < 5) {
           UseSharedPtr(res) ;
          }
      }

      void SharedPtr() {
        auto test = std::make_shared<Resource>();
        std::cout << test.use_count() << std::endl;
        UseSharedPtr(test);
        std::cout <<  test.use_count() << std::endl;
      };

  };
}
