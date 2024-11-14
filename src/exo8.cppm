module;


// Import rapide de la bibliothèque standard
import std;

// Nommage et exportation de ce module
export module exo8;

// On met toutes les classes du module dans un espace de nom pour éviter les conflits
export namespace exo8 {

 struct Node {
   int data;
   std::unique_ptr<Node> left;
   std::unique_ptr<Node> right;

   explicit Node(const int value) : data(value), left(nullptr), right(nullptr) {}

 };

  class BinaryTree {
  public:
    //je définis le type de la racine de l'arbre qui est un unique_ptr et découle de la classe Node
    std::unique_ptr<Node> root;
    //La racine est donc initialisée à nullptr
    BinaryTree() : root(nullptr) {}

    void Insert(const int value) {
      if (root == nullptr) {
        root = std::make_unique<Node>(value);
      } else {
        RecursiveInsert(root, value);
      }
    }

    void Traversal(const std::function<void(const int value)>& func) {
      if (root != nullptr) {
        RecursiveTraversal(root, func);
      }
    };

  private:

    void RecursiveInsert(std::unique_ptr<Node> &node, const int value) {
      //Si la valeur  est inférieur au noeud, on check l'enfant gauche
      if (value < node->data) {
        //On regarde si l'enfant gauche est null
        if (node->left == nullptr) {
          //Sil gauche est null on insert la valeur dans l'enfant gauche
          node->left = std::make_unique<Node>(value);
          //Si gauche a déjà une valeur on descend d'un niveau en appelant la recursive
        } else {
          RecursiveInsert(node->left, value);
        }
        //Si la valeur est supérieure à la valeur actuelle on check l'enfant droite
      } else if (value > node->data) {
        if (node->right == nullptr) {
          //Si l'enfant droite est null on insert la valeur dans l'enfant droite
          node->right = std::make_unique<Node>(value);
          //Si droite a déjà une valeur on descend d'un niveau en appelant la recursive
        } else {
          RecursiveInsert(node->right, value);
        }
      }
    }


    void RecursiveTraversal(const std::unique_ptr<Node>& node, const std::function<void(int)>& lambda) const {
      if (node != nullptr) {
        RecursiveTraversal(node->left, lambda);
        lambda(node->data);
        RecursiveTraversal(node->right, lambda);
      }
    };



      class Application {
      public:
        Application() {
          std::cout << "Hello from exo8::Application()\n"  << std::endl;

        };
      };
    };
  }
