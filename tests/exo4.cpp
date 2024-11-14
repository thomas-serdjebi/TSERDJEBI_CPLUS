#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

// Importation de l'exercice
import exo4;
import std;
using namespace exo4;

TEST_CASE("Exo4", "[Vector4]") {
    std::cout << "TEST EXO 4" << std::endl;
    const auto circle = Circle{1.2};
    REQUIRE(std::format("{0:.2f}", circle.Perimeter()) == "7.54");
}