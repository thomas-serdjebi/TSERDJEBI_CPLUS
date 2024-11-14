#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

// Importation de l'exercice
import exo5;
import std;
using namespace exo5;

TEST_CASE("Exo5", "[Vector5]") {
    std::cout << "TEST EXO 5 " << std::endl;
    REQUIRE(std::format("{0:.2f}", Polygon{{1.0,2.0,3.0}}.Perimeter()) == "6.00");
    REQUIRE(std::format("{0:.2f}", Rectangle{1.0,2.0}.Perimeter()) == "6.00");
    REQUIRE(std::format("{0:.2f}", Square{1.0}.Perimeter()) == "4.00");
}