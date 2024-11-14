#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

// Importation de l'exercice
import exo7;
import std;
using namespace exo7;

TEST_CASE("Exo7", "[Vector7]") {
    std::cout << "TEST EXO 7 " << std::endl;

    //std::vector<int> vec = {1, 2, 3, 5, 5};
    //std::cout << "Vector 1 contents: ";
    //exo6::VectorUtils::Print(vec);
    //std::cout << std::endl;


    //std::vector<int> vec2 = {2, 4, 4, 3, 5, 8};
    //std::cout << "Vector 2 contents: ";
    //exo6::VectorUtils::SortAndRemoveDuplicates(vec2);
    //exo6::VectorUtils::Print(vec2);
    //std::cout << std::endl;

    //auto vec = std::vector<int>{1, 4, 5, 2, 1, 7, 8, 5, 8, 2, 9};
    //VectorUtils::SortAndRemoveDuplicates(vec);
    //const auto result = std::vector<int>{1, 2, 4, 5, 7, 8, 9};
    //REQUIRE(vec == result);
    //const auto vecConst = vec;
    //REQUIRE(VectorUtils::CountGreatersThan(vecConst, 5) == 3);
}
