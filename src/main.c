/*
** EPITECH PROJECT, 2020
** Mul_my_defender
** File description:
** Main function of the Defender.
*/

#include "my.h"
#include "struct.h"

void print_h_two(void)
{
    my_putstr("\tIf you want more informations, go on the Help menu!");
    my_putstr(RED);
    my_putstr("\nHave fun !\n\n");
}

void print_h(void)
{
    my_putstr(RED);
    my_putstr("\nWelcome to King's Mercy !\n\n");
    my_putstr(CYAN);
    my_putstr("USAGE :\n");
    my_putstr(NORMAL);
    my_putstr("\t./my_defender\n\n");
    my_putstr(CYAN);
    my_putstr("OPTIONS :\n");
    my_putstr(NORMAL);
    my_putstr("\t-h            print the usage and quit.\n\n");
    my_putstr(CYAN);
    my_putstr("USER INTERACTIONS :\n");
    my_putstr(NORMAL);
    my_putstr("\tYou can create your own map via the folder 'legend'.\n");
    my_putstr("\tESCAPE_KEY    to go back \
    or in game to launch the pause menu.\n");
    my_putstr("\tH_KEY         to show the locations of the towers.\n");
    print_h_two();
}

int main(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')) {
        print_h();
        return (0);
    }
    else if (ac != 1 && ac != 2) {
        my_putstr("Use the command ./my_defender -h for more information.\n");
        return (0);
    }
    if (ac == 1) {
        all *all = init_all(0, "rien");
        my_menu(all);
        all = clear_all(all);
    } else if (ac == 2) {
        all *all = init_all(1, av[1]);
        my_menu(all);
        all = clear_all(all);
    }
    return (0);
}