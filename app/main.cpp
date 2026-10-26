#include "uincampus/version.hpp"

#include <print>

int main() // NOLINT(bugprone-exception-escape): formats vérifiés à la compilation
{
    std::println("UIN-Campus — Système de gestion académique");
    std::println("Version {}", uin::version());
}