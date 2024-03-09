#include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
int x = 300, y = 300, r = 20;
/*
	function iDraw() is called again and again by the system.

	*/
int current_page = -1;
int submenu_page = 0;
int Menu_option = 0;
int submenu = 0;
int l;
int sound = 1;
int Recipe_sub[11];
int biryani_index = 0;
int bengli_index = 0;
int fast_index = 0;
int kebab_index = 0;
int salad_index = 0;
int soup_index = 0;
int achar_index = 0;
int vegetable_index = 0;
int dessert_index = 0;
int pitha_index = 0;
int biriyani_menu[5][6];
int bengali_menu[5][6];
int fast_menu[5][6];
int kebab_menu[5][6];
int salad_menu[3][6];
int soup_menu[4][6];
int achar_menu[3][6];
int vegetable_menu[4][6];
int dessert_menu[4][6];
int pitha_menu[3][6];
int biryani_fix = 0;
int bengali_fix = 0;
int fast_fix = 0;
int kebab_fix = 0;
int salad_fix = 0;
int soup_fix = 0;
int achar_fix = 0;
int vegetable_fix = 0;
int dessert_fix = 0;
int pitha_fix = 0;
int tribal_fix = 0;
int i_biryani = 0;
int i_bengali = 0;
int i_fast = 0;
int i_kebab = 0;
int i_salad = 0;
int i_soup = 0;
int i_achar = 0;
int i_vegetable = 0;
int i_dessert = 0;
int i_pitha = 0;
int i_tribal = 0;
int ingre_flag = 0;
int favorite_flag = 0;
int nuser, npass;
char user[20], pass[20], spass[20], cuser[20];
int auth = -1; //-1 null state, 0 wrong user, 2 wrong pass, 1 ok;
int iu = 0;
int ip = 0;
char nutrition_facts[10][50] = {"pictures\\Nutrition facts\\Nutrition_facts_1.jpg", "pictures\\Nutrition facts\\Nutrition_facts_2.jpg",
								"pictures\\Nutrition facts\\Nutrition_facts_3.jpg", "pictures\\Nutrition facts\\Nutrition_facts_4.jpg",
								"pictures\\Nutrition facts\\Nutrition_facts_5.jpg", "pictures\\Nutrition facts\\Nutrition_facts_6.jpg",
								"pictures\\Nutrition facts\\Nutrition_facts_7.jpg", "pictures\\Nutrition facts\\Nutrition_facts_8.jpg",
								"pictures\\Nutrition facts\\Nutrition_facts_9.jpg", "pictures\\Nutrition facts\\Nutrition_facts_10.jpg"};
char welcome_page[100][100] = {"pictures\\Welcome\\1.bmp", "pictures\\Welcome\\2.bmp", "pictures\\Welcome\\3.bmp", "pictures\\Welcome\\4.bmp", "pictures\\Welcome\\5.bmp",
							   "pictures\\Welcome\\6.bmp", "pictures\\Welcome\\7.bmp", "pictures\\Welcome\\8.bmp", "pictures\\Welcome\\9.bmp", "pictures\\Welcome\\10.bmp",
							   "pictures\\Welcome\\11.bmp", "pictures\\Welcome\\12.bmp", "pictures\\Welcome\\13.bmp", "pictures\\Welcome\\14.bmp", "pictures\\Welcome\\15.bmp",
							   "pictures\\Welcome\\16.bmp", "pictures\\Welcome\\17.bmp", "pictures\\Welcome\\18.bmp", "pictures\\Welcome\\19.bmp", "pictures\\Welcome\\20.bmp",
							   "pictures\\Welcome\\21.bmp", "pictures\\Welcome\\22.bmp", "pictures\\Welcome\\23.bmp", "pictures\\Welcome\\24.bmp", "pictures\\Welcome\\25.bmp",
							   "pictures\\Welcome\\26.bmp", "pictures\\Welcome\\27.bmp", "pictures\\Welcome\\28.bmp", "pictures\\Welcome\\29.bmp", "pictures\\Welcome\\30.bmp",
							   "pictures\\Welcome\\31.bmp", "pictures\\Welcome\\32.bmp", "pictures\\Welcome\\33.bmp", "pictures\\Welcome\\34.bmp", "pictures\\Welcome\\35.bmp",
							   "pictures\\Welcome\\36.bmp", "pictures\\Welcome\\37.bmp", "pictures\\Welcome\\38.bmp", "pictures\\Welcome\\39.bmp", "pictures\\Welcome\\40.bmp",
							   "pictures\\Welcome\\41.bmp", "pictures\\Welcome\\42.bmp", "pictures\\Welcome\\43.bmp", "pictures\\Welcome\\44.bmp", "pictures\\Welcome\\45.bmp",
							   "pictures\\Welcome\\46.bmp", "pictures\\Welcome\\47.bmp", "pictures\\Welcome\\48.bmp", "pictures\\Welcome\\49.bmp", "pictures\\Welcome\\50.bmp",
							   "pictures\\Welcome\\51.bmp", "pictures\\Welcome\\52.bmp", "pictures\\Welcome\\53.bmp", "pictures\\Welcome\\54.bmp", "pictures\\Welcome\\55.bmp",
							   "pictures\\Welcome\\56.bmp", "pictures\\Welcome\\57.bmp", "pictures\\Welcome\\58.bmp", "pictures\\Welcome\\59.bmp", "pictures\\Welcome\\60.bmp",
							   "pictures\\Welcome\\66.bmp", "pictures\\Welcome\\67.bmp", "pictures\\Welcome\\68.bmp", "pictures\\Welcome\\69.bmp", "pictures\\Welcome\\70.bmp",
							   "pictures\\Welcome\\71.bmp", "pictures\\Welcome\\72.bmp", "pictures\\Welcome\\73.bmp", "pictures\\Welcome\\74.bmp", "pictures\\Welcome\\75.bmp",
							   "pictures\\Welcome\\76.bmp", "pictures\\Welcome\\77.bmp", "pictures\\Welcome\\78.bmp", "pictures\\Welcome\\79.bmp", "pictures\\Welcome\\80.bmp"};
int ingre_list[42][13] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, {13, 14, 3, 15, 8, 16, 6, 17, 18, 9, 10, 19}, {20, 21, 3, 4, 5, 22, 23, 8, 24, 25, 12, 26}, {27, 28, 29, 10, 5, 3, 30, 4, 31, 7, 11, 12}, {32, 14, 6, 10, 33, 34, 15, 31, 35, 36, 12, 37}, {38, 7, 39, 10, 40, 8, 5, 4, 41, 28, 42, 23}, {38, 22, 43, 3, 28, 7, 4, 44, 36, 22, 45, 46}, {47, 48, 3, 22, 49, 4, 36, 10, 29, 50, 2, 51}, {38, 4, 7, 52, 53, 12, 28, 54, 15, 6, 49, 41}, {27, 55, 37, 44, 4, 6, 25, 35, 12, 48, 38}, {56, 57, 3, 10, 26, 8, 28, 4, 44, 7, 58, 12}, {27, 57, 3, 10, 5, 8, 28, 4, 6, 7, 36, 29}, {47, 59, 3, 10, 15, 36, 28, 4, 44, 7, 37, 60}, {47, 59, 3, 10, 26, 36, 28, 4, 44, 7, 61, 12}, {27, 7, 3, 10, 26, 6, 28, 4, 62, 7, 37, 12}, {56, 28, 50, 10, 48, 42, 63, 64, 65, 53, 66, 4}, {67, 68, 69, 10, 70, 65, 71, 72, 73, 43, 63, 53}, {73, 74, 44, 28, 68, 19, 30, 10, 43, 7, 37, 12}, {34, 48, 3, 10, 26, 6, 28, 8, 75, 76, 43, 38}, {77, 76, 78, 38, 26, 8, 28, 3, 42, 43, 64, 44}, {76, 79, 30, 10, 31, 45, 28, 4, 44, 25, 35, 33}, {80, 30, 3, 10, 64, 65, 28, 45, 81, 82, 31, 33}, {83, 1, 48, 10, 19, 84, 28, 4, 85, 65, 42, 8}, {86, 87, 3, 10, 19, 60, 28, 4, 42, 88, 45, 82}, {80, 86, 3, 10, 45, 44, 28, 4, 42, 60, 33, 88}, {76, 89, 3, 10, 26, 90, 28, 4, 22, 91, 42, 87}, {92, 34, 53, 10, 26, 6, 28, 4, 50, 14, 36, 33}, {93, 75, 43, 10, 26, 80, 28, 4, 3, 44, 64, 19}, {47, 48, 3, 10, 26, 6, 50, 94, 95, 67, 63, 96}, {34, 97, 33, 10, 26, 98, 63, 99, 3, 43, 50, 64}, {83, 86, 3, 10, 26, 6, 28, 68, 99, 63, 100, 44},{60, 33, 25, 10, 65, 107, 104, 35, 12, 105, 24, 31}, {60, 101, 33, 10, 26, 93, 48, 103, 45, 102, 100, 98}, {60, 98, 33, 10, 26, 103, 25, 35, 104, 105, 45, 12}, {93, 5, 42, 102, 106, 105, 33, 107, 25, 35, 10, 108},{109, 19, 33, 10, 26, 113, 112, 60, 35, 31, 107, 105}, {34, 109, 110, 10, 26, 60, 35, 33, 111, 112, 25, 12}, {109, 19, 33, 10, 26, 35, 25, 60, 112, 31, 79, 98}, {115, 65, 33, 10, 15, 6, 28, 37, 25, 31, 36, 12}, {114, 10, 14, 33, 15, 3, 28, 25, 35, 6, 24, 12}, {116, 65, 33, 10, 15, 6, 28, 25, 31, 36, 37, 12}};
int ingre_sup[42][13];
int fav_sup[42];
char ingre_pic[117][50] = {
	"pictures\\grocery\\1.bmp", "pictures\\grocery\\2.bmp", "pictures\\grocery\\3.bmp", "pictures\\grocery\\4.bmp", "pictures\\grocery\\5.bmp", "pictures\\grocery\\6.bmp",
	"pictures\\grocery\\7.bmp", "pictures\\grocery\\8.bmp", "pictures\\grocery\\9.bmp", "pictures\\grocery\\10.bmp", "pictures\\grocery\\11.bmp", "pictures\\grocery\\12.bmp",
	"pictures\\grocery\\13.bmp", "pictures\\grocery\\14.bmp", "pictures\\grocery\\15.bmp", "pictures\\grocery\\16.bmp", "pictures\\grocery\\17.bmp", "pictures\\grocery\\18.bmp",
	"pictures\\grocery\\19.bmp", "pictures\\grocery\\20.bmp", "pictures\\grocery\\21.bmp", "pictures\\grocery\\22.bmp", "pictures\\grocery\\23.bmp", "pictures\\grocery\\24.bmp",
	"pictures\\grocery\\25.bmp", "pictures\\grocery\\26.bmp", "pictures\\grocery\\27.bmp", "pictures\\grocery\\28.bmp", "pictures\\grocery\\29.bmp", "pictures\\grocery\\30.bmp",
	"pictures\\grocery\\31.bmp", "pictures\\grocery\\32.bmp", "pictures\\grocery\\33.bmp", "pictures\\grocery\\34.bmp", "pictures\\grocery\\35.bmp", "pictures\\grocery\\36.bmp",
	"pictures\\grocery\\37.bmp", "pictures\\grocery\\38.bmp", "pictures\\grocery\\39.bmp", "pictures\\grocery\\40.bmp", "pictures\\grocery\\41.bmp", "pictures\\grocery\\42.bmp",
	"pictures\\grocery\\43.bmp", "pictures\\grocery\\44.bmp", "pictures\\grocery\\45.bmp", "pictures\\grocery\\46.bmp", "pictures\\grocery\\47.bmp", "pictures\\grocery\\48.bmp",
	"pictures\\grocery\\49.bmp", "pictures\\grocery\\50.bmp", "pictures\\grocery\\51.bmp", "pictures\\grocery\\52.bmp", "pictures\\grocery\\53.bmp", "pictures\\grocery\\54.bmp",
	"pictures\\grocery\\55.bmp", "pictures\\grocery\\56.bmp", "pictures\\grocery\\57.bmp", "pictures\\grocery\\58.bmp", "pictures\\grocery\\59.bmp", "pictures\\grocery\\60.bmp",
	"pictures\\grocery\\61.bmp", "pictures\\grocery\\62.bmp", "pictures\\grocery\\63.bmp", "pictures\\grocery\\64.bmp", "pictures\\grocery\\65.bmp", "pictures\\grocery\\66.bmp",
	"pictures\\grocery\\67.bmp", "pictures\\grocery\\68.bmp", "pictures\\grocery\\69.bmp", "pictures\\grocery\\70.bmp", "pictures\\grocery\\71.bmp", "pictures\\grocery\\72.bmp",
	"pictures\\grocery\\73.bmp", "pictures\\grocery\\74.bmp", "pictures\\grocery\\75.bmp", "pictures\\grocery\\76.bmp", "pictures\\grocery\\77.bmp", "pictures\\grocery\\78.bmp",
	"pictures\\grocery\\79.bmp", "pictures\\grocery\\80.bmp", "pictures\\grocery\\81.bmp", "pictures\\grocery\\82.bmp", "pictures\\grocery\\83.bmp", "pictures\\grocery\\84.bmp",
	"pictures\\grocery\\85.bmp", "pictures\\grocery\\86.bmp", "pictures\\grocery\\87.bmp", "pictures\\grocery\\88.bmp", "pictures\\grocery\\89.bmp", "pictures\\grocery\\90.bmp",
	"pictures\\grocery\\91.bmp", "pictures\\grocery\\92.bmp", "pictures\\grocery\\93.bmp", "pictures\\grocery\\94.bmp", "pictures\\grocery\\95.bmp", "pictures\\grocery\\96.bmp",
	"pictures\\grocery\\97.bmp", "pictures\\grocery\\98.bmp", "pictures\\grocery\\99.bmp", "pictures\\grocery\\100.bmp", "pictures\\grocery\\101.bmp", "pictures\\grocery\\102.bmp",
	"pictures\\grocery\\103.bmp", "pictures\\grocery\\104.bmp", "pictures\\grocery\\105.bmp", "pictures\\grocery\\106.bmp", "pictures\\grocery\\107.bmp", "pictures\\grocery\\108.bmp",
	"pictures\\grocery\\109.bmp", "pictures\\grocery\\110.bmp", "pictures\\grocery\\111.bmp", "pictures\\grocery\\112.bmp", "pictures\\grocery\\113.bmp", "pictures\\grocery\\114.bmp",
	"pictures\\grocery\\115.bmp", "pictures\\grocery\\116.bmp"};
char recipe_pic[42][80] = {"pictures\\fav\\1.bmp", "pictures\\fav\\2.bmp", "pictures\\fav\\3.bmp", "pictures\\fav\\4.bmp", "pictures\\fav\\5.bmp", "pictures\\fav\\6.bmp", "pictures\\fav\\7.bmp", "pictures\\fav\\8.bmp",
						   "pictures\\fav\\9.bmp", "pictures\\fav\\10.bmp", "pictures\\fav\\11.bmp", "pictures\\fav\\12.bmp", "pictures\\fav\\13.bmp", "pictures\\fav\\14.bmp", "pictures\\fav\\15.bmp", "pictures\\fav\\16.bmp",
						   "pictures\\fav\\17.bmp", "pictures\\fav\\18.bmp", "pictures\\fav\\19.bmp", "pictures\\fav\\20.bmp", "pictures\\fav\\21.bmp", "pictures\\fav\\22.bmp", "pictures\\fav\\23.bmp", "pictures\\fav\\24.bmp",
						   "pictures\\fav\\25.bmp", "pictures\\fav\\26.bmp", "pictures\\fav\\27.bmp", "pictures\\fav\\28.bmp", "pictures\\fav\\29.bmp", "pictures\\fav\\30.bmp", "pictures\\fav\\31.bmp", "pictures\\fav\\32.bmp",
						   "pictures\\fav\\33.bmp", "pictures\\fav\\34.bmp", "pictures\\fav\\35.bmp", "pictures\\fav\\36.bmp", "pictures\\fav\\37.bmp", "pictures\\fav\\38.bmp", "pictures\\fav\\39.bmp", "pictures\\fav\\40.bmp",
						   "pictures\\fav\\41.bmp"};
int favorites[42];
int ingre_num[11];
int fav_num[10];
int flag_biryani = 5;
int flag_bengali = 5;
int flag_fast = 5;
int flag_kebab = 5;
int flag_salad = 5;
int flag_soup = 5;
int flag_achar = 5;
int flag_vegetable = 5;
int flag_dessert = 5;
int flag_pitha = 5;
int flag_tribal = 5;
int flag_ingre = 0;
static int welcome_index = 0;
int co_ord_x;
int co_ord_y;
int store;
int flag_over = 0;
int about =0;
// int biryani_rec[5];
void iDrawSubMenu();
void iDrawMenu();
void Recipes();
void iTips();
void biryani();
void bengali();
void fast();
void kebab();
void salad();
void soup();
void achar();
void vegetable();
void dessert();
void pitha();
void tribal();
void draw_biryani_menu();
void draw_bengali_menu();
void draw_fast_menu();
void draw_kebab_menu();
void draw_salad_menu();
void draw_soup_menu();
void draw_achar_menu();
void draw_vegetable_menu();
void draw_dessert_menu();
void draw_pitha_menu();
void draw_tribal_menu();
void welcome();
void ingre_hover(int mx, int my);
void ingre_click(int mx, int my, int a);
void match_grocery();
void print_grocery();
void ingre_tick(int b);
void fav(int mx, int my, int b);
void match_fav();
void fav_draw(int b);
void ifab();
void accButton();
void accin();
void login();
int check();

void filein_match()
{
	FILE *fp = fopen("a.txt", "w");
	if (fp == NULL)
		printf("ERROR");
	for (int i = 0; i < 11; i++)
	{
		fprintf(fp, "%d ", ingre_num[i]);
	}
	fclose(fp);
}
void fileout_match()
{
	FILE *fp = fopen("a.txt", "r");
	if (fp == NULL)
		printf("ERROR");
	for (int i = 0; i < 11; i++)
	{
		fscanf(fp, "%d", &ingre_num[i]);
		fgetc(fp);
	}
	fclose(fp);
}

void filein_fav()
{
	FILE *fp = fopen("b.txt", "w");
	if (fp == NULL)
		printf("ERROR");
	for (int i = 0; i < 10; i++)
	{
		fprintf(fp, "%d ", fav_num[i]);
	}
	fclose(fp);
}
void fileout_fav()
{
	FILE *fp = fopen("b.txt", "r");
	if (fp == NULL)
		printf("ERROR");
	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d", &fav_num[i]);
	}
	fclose(fp);
}

void iDraw()
{
	// place your drawing codes here
	iClear();
	// printf("%d\n",Menu_option);
	// for (int i = 0; i < 11; i++)
	// {
	// 	printf("%d", ingre_num[i]);
	// }
	// printf("\n");
	if (current_page == -1)
	{
		iShowBMP(0, 0, welcome_page[welcome_index]);
	}
	else if (current_page == 0)
	{
		iShowBMP(0, 0, "pictures\\login\\login.bmp");
		iSetColor(0, 0, 0);
		iText(160, 435, user, GLUT_BITMAP_HELVETICA_18);

		iSetColor(0, 0, 0);
		iText(160, 330, spass, GLUT_BITMAP_HELVETICA_18);
		if (auth == 0)
			iText(160, 435, "Wrong Username", GLUT_BITMAP_HELVETICA_18);
		if (auth == 2)
			iText(160, 435, "Wrong Password", GLUT_BITMAP_HELVETICA_18);
	}
	else if (current_page == 1 && submenu_page == 0)
	{
		iDrawMenu();
	}
	else if (current_page == 1 && (submenu_page == 1 || submenu_page == 2))
	{
		iDrawSubMenu();
	}
	// if (current_page == 5)
	// {
	// 	iTips();
	// }
	else if (current_page == 2 && Recipe_sub[0] == 1)
	{
		draw_bengali_menu();
		bengali();
	}
	else if (current_page == 2 && Recipe_sub[1] == 1)
	{
		draw_kebab_menu();
		kebab();
	}
	else if (current_page == 2 && Recipe_sub[2] == 1)
	{
		draw_biryani_menu();
		biryani();
	}
	else if (current_page == 2 && Recipe_sub[3] == 1)
	{
		draw_salad_menu();
		salad();
	}
	else if (current_page == 2 && Recipe_sub[4] == 1)
	{
		draw_vegetable_menu();
		vegetable();
	}
	else if (current_page == 2 && Recipe_sub[5] == 1)
	{
		draw_soup_menu();
		soup();
	}
	else if (current_page == 2 && Recipe_sub[6] == 1)
	{
		draw_fast_menu();
		fast();
	}
	else if (current_page == 2 && Recipe_sub[7] == 1)
	{
		draw_dessert_menu();
		dessert();
	}
	else if (current_page == 2 && Recipe_sub[8] == 1)
	{
		draw_pitha_menu();
		pitha();
	}
	else if (current_page == 2 && Recipe_sub[9] == 1)
	{
		draw_achar_menu();
		achar();
	}
	else if (current_page == 5)
	{
		iTips();
	}
	else if (current_page == 6)
	{
		iShowBMP(0, 0, "pictures\\grocery\\grocery_main.bmp");
		iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		iShowBMP(1100, 480, "pictures\\Jump\\Clear list.bmp");
		print_grocery();
	}
	else if (current_page == 4)
	{
		iShowBMP(0, 0, "pictures\\fav\\fav_page.bmp");
		iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		iShowBMP(1100, 480, "pictures\\Jump\\Clear list.bmp");
		ifab();
	}
	else if (current_page == 7)
	{
		draw_tribal_menu();
		tribal();
	}
	else if (current_page == 8 && sound == 1 && about == 0)
	{
		iShowBMP(0, 0, "pictures\\sound\\sound_1.bmp");
		iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
	}
	else if (current_page == 8 && sound == 0 && about ==0)
	{
		iShowBMP(0, 0, "pictures\\sound\\sound_0.bmp");
		iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
	}
	else if (current_page == 8 && about == 1)
	{
		iShowBMP(0, 0, "pictures\\sound\\About.bmp");
		iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
	}
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/

void iMouseMove(int mx, int my)
{
	// printf("x = %d, y= %d\n",mx,my);
	/*if(my<500 && my>400 && mx>200 &&mx<350){
		Menu_option[1]==1;
	}
	else{
		Menu_option[1]==0;
	}*/
	// if(mx)
	// place your codes here
}
void iMouseHover(int mx, int my)
{

	if (current_page == 1 && submenu_page == 0)
	{
		if ((mx > 320 && mx < 550) && (my > 390 && my < 530))
		{
			Menu_option = 1;
			// printf("x = %d, y= %d\n", mx, my);
			// printf("%d\n", Menu_option);
		}
		else if ((mx > 620 && mx < 860) && (my > 385 && my < 525))
		{
			Menu_option = 2;
			// printf("x = %d, y= %d\n", mx, my);
			// printf("%d\n", Menu_option);
		}
		else if ((mx > 190 && mx < 420) && (my > 150 && my < 285))
		{
			Menu_option = 3;
			// printf("x = %d, y= %d\n", mx, my);
			// printf("%d\n", Menu_option);
		}
		else if ((mx > 475 && mx < 705) && (my > 150 && my < 285))
		{
			Menu_option = 4;
			// printf("x = %d, y= %d\n", mx, my);
			// printf("%d\n", Menu_option);
		}
		else if ((mx > 760 && mx < 990) && (my > 150 && my < 285))
		{
			Menu_option = 5;
			// printf("x = %d, y= %d\n", mx, my);
			// printf("%d\n", Menu_option);
		}
		else
		{
			Menu_option = 0;
		}
	}
	else if (current_page == 1 && submenu_page == 1)
	{
		if (mx > 115 && mx < 360 && my > 328 && my < 490)
		{
			submenu = 1;
		}
		else if (mx > 450 && mx < 695 && my > 328 && my < 490)
		{
			submenu = 2;
		}
		else if (mx > 795 && mx < 1030 && my > 328 && my < 490)
		{
			submenu = 3;
		}
		else if (mx > 280 && mx < 527 && my > 80 && my < 245)
		{
			submenu = 4;
		}
		else if (mx > 620 && mx < 865 && my > 80 && my < 240)
		{
			submenu = 5;
		}
		else
		{
			submenu = 0;
		}
	}
	else if (current_page == 1 && submenu_page == 2)
	{
		if (mx > 171 && mx < 416 && my > 332 && my < 498)
		{
			// printf("%d\n", submenu);
			submenu = 8;
		}
		else if (mx > 508 && mx < 758 && my > 332 && my < 498)
		{
			// printf("%d\n", submenu);
			submenu = 9;
		}
		else if (mx > 840 && mx < 1090 && my > 331 && my < 498)
		{
			// printf("%d\n", submenu);
			submenu = 10;
		}
		else if (mx > 329 && mx < 584 && my > 85 && my < 253)
		{
			// printf("%d\n", submenu);
			submenu = 11;
		}
		else if (mx > 670 && mx < 920 && my > 85 && my < 253)
		{
			// printf("%d\n", submenu);
			submenu = 12;
		}
		else
		{
			submenu = 6;
		}
	}
	else if (Recipe_sub[0] == 1 && bengali_fix == 1 && bengali_menu[0][1] == 0 && bengali_menu[1][1] == 0 && bengali_menu[2][1] == 0 && bengali_menu[3][1] == 0 && bengali_menu[4][1] == 0)
	{
		if (mx > 30 && mx < 290 && my > 420 && my < 610)
		{
			flag_bengali = 0;
		}
		else if (mx > 385 && mx < 645 && my > 420 && my < 610)
		{
			flag_bengali = 1;
		}
		else if (mx > 735 && mx < 998 && my > 420 && my < 610)
		{
			flag_bengali = 2;
		}
		else if (mx > 218 && mx < 483 && my > 115 && my < 300)
		{
			flag_bengali = 3;
		}
		else if (mx > 580 && mx < 840 && my > 115 && my < 300)
		{
			flag_bengali = 4;
		}
		else
		{
			flag_bengali = 5;
		}
	}
	else if (Recipe_sub[0] == 1 && bengali_fix == 0 && (bengali_menu[0][1] == 1 || bengali_menu[1][1] == 1 || bengali_menu[2][1] == 1 || bengali_menu[3][1] == 1 || bengali_menu[4][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[1] == 1 && kebab_fix == 1 && kebab_menu[0][1] == 0 && kebab_menu[1][1] == 0 && kebab_menu[2][1] == 0 && kebab_menu[3][1] == 0 && kebab_menu[4][1] == 0)
	{
		if (mx > 30 && mx < 290 && my > 420 && my < 610)
		{
			flag_kebab = 0;
		}
		else if (mx > 385 && mx < 645 && my > 420 && my < 610)
		{
			flag_kebab = 1;
		}
		else if (mx > 735 && mx < 998 && my > 420 && my < 610)
		{
			flag_kebab = 2;
		}
		else if (mx > 218 && mx < 483 && my > 115 && my < 300)
		{
			flag_kebab = 3;
		}
		else if (mx > 580 && mx < 840 && my > 115 && my < 300)
		{
			flag_kebab = 4;
		}
		else
		{
			flag_kebab = 5;
		}
	}
	else if (Recipe_sub[1] == 1 && kebab_fix == 0 && (kebab_menu[0][1] == 1 || kebab_menu[1][1] == 1 || kebab_menu[2][1] == 1 || kebab_menu[3][1] == 1 || kebab_menu[4][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[2] == 1 && biryani_fix == 1 && biriyani_menu[0][1] == 0 && biriyani_menu[1][1] == 0 && biriyani_menu[2][1] == 0 && biriyani_menu[3][1] == 0 && biriyani_menu[4][1] == 0)
	{
		if (mx > 30 && mx < 290 && my > 420 && my < 610)
		{
			flag_biryani = 0;
		}
		else if (mx > 385 && mx < 645 && my > 420 && my < 610)
		{
			flag_biryani = 1;
		}
		else if (mx > 735 && mx < 998 && my > 420 && my < 610)
		{
			flag_biryani = 2;
		}
		else if (mx > 218 && mx < 483 && my > 115 && my < 300)
		{
			flag_biryani = 3;
		}
		else if (mx > 580 && mx < 840 && my > 115 && my < 300)
		{
			flag_biryani = 4;
		}
		else
		{
			flag_biryani = 5;
		}
	}
	else if (Recipe_sub[2] == 1 && biryani_fix == 0 && (biriyani_menu[0][1] == 1 || biriyani_menu[1][1] == 1 || biriyani_menu[2][1] == 1 || biriyani_menu[3][1] == 1 || biriyani_menu[4][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[3] == 1 && salad_fix == 1 && salad_menu[0][1] == 0 && salad_menu[1][1] == 0 && salad_menu[2][1] == 0)
	{
		if (mx > 32 && mx < 315 && my > 280 && my < 475)
		{
			flag_salad = 0;
		}
		else if (mx > 365 && mx < 655 && my > 285 && my < 475)
		{
			flag_salad = 1;
		}
		else if (mx > 705 && mx < 980 && my > 285 && my < 475)
		{
			flag_salad = 2;
		}
		else
		{
			flag_salad = 5;
		}
	}
	else if (Recipe_sub[3] == 1 && salad_fix == 0 && (salad_menu[0][1] == 1 || salad_menu[1][1] == 1 || salad_menu[2][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[4] == 1 && vegetable_fix == 1 && vegetable_menu[0][1] == 0 && vegetable_menu[1][1] == 0 && vegetable_menu[2][1] == 0 && vegetable_menu[3][1] == 0)
	{
		if (mx > 175 && mx < 465 && my > 400 && my < 610)
		{
			flag_vegetable = 0;
		}
		else if (mx > 585 && mx < 895 && my > 400 && my < 610)
		{
			flag_vegetable = 1;
		}
		else if (mx > 170 && mx < 480 && my > 110 && my < 310)
		{
			flag_vegetable = 2;
		}
		else if (mx > 585 && mx < 900 && my > 115 && my < 310)
		{
			flag_vegetable = 3;
		}
		else
		{
			flag_vegetable = 5;
		}
	}
	else if (Recipe_sub[4] == 1 && vegetable_fix == 0 && (vegetable_fix == 1 || vegetable_menu[0][1] == 1 || vegetable_menu[1][1] == 1 || vegetable_menu[2][1] == 1 || vegetable_menu[3][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[5] == 1 && soup_fix == 1 && soup_menu[0][1] == 0 && soup_menu[1][1] == 0 && soup_menu[2][1] == 0 && soup_menu[3][1] == 0)
	{
		if (mx > 175 && mx < 465 && my > 400 && my < 610)
		{
			flag_soup = 0;
		}
		else if (mx > 585 && mx < 895 && my > 400 && my < 610)
		{
			flag_soup = 1;
		}
		else if (mx > 170 && mx < 480 && my > 110 && my < 310)
		{
			flag_soup = 2;
		}
		else if (mx > 585 && mx < 900 && my > 115 && my < 310)
		{
			flag_soup = 3;
		}
		else
		{
			flag_soup = 5;
		}
	}
	else if (Recipe_sub[5] == 1 && soup_fix == 0 && (soup_menu[0][1] == 1 || soup_menu[1][1] == 1 || soup_menu[2][1] == 1 || soup_menu[3][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[6] == 1 && fast_fix == 1 && fast_menu[0][1] == 0 && fast_menu[1][1] == 0 && fast_menu[2][1] == 0 && fast_menu[3][1] == 0 && fast_menu[4][1] == 0)
	{
		if (mx > 30 && mx < 290 && my > 420 && my < 610)
		{
			flag_fast = 0;
		}
		else if (mx > 385 && mx < 645 && my > 420 && my < 610)
		{
			flag_fast = 1;
		}
		else if (mx > 735 && mx < 998 && my > 420 && my < 610)
		{
			flag_fast = 2;
		}
		else if (mx > 218 && mx < 483 && my > 115 && my < 300)
		{
			flag_fast = 3;
		}
		else if (mx > 580 && mx < 840 && my > 115 && my < 300)
		{
			flag_fast = 4;
		}
		else
		{
			flag_fast = 5;
		}
	}
	else if (Recipe_sub[6] == 1 && fast_fix == 0 && (fast_menu[0][1] == 1 || fast_menu[1][1] == 1 || fast_menu[2][1] == 1 || fast_menu[3][1] == 1 || fast_menu[4][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[7] == 1 && dessert_fix == 1 && dessert_menu[0][1] == 0 && dessert_menu[1][1] == 0 && dessert_menu[2][1] == 0 && dessert_menu[3][1] == 0)
	{
		if (mx > 185 && mx < 470 && my > 395 && my < 585)
		{
			flag_dessert = 0;
		}
		else if (mx > 595 && mx < 880 && my > 395 && my < 585)
		{
			flag_dessert = 1;
		}
		else if (mx > 185 && mx < 470 && my > 105 && my < 300)
		{
			flag_dessert = 2;
		}
		else if (mx > 605 && mx < 890 && my > 105 && my < 300)
		{
			flag_dessert = 3;
		}
		else
		{
			flag_dessert = 5;
		}
	}
	else if (Recipe_sub[7] == 1 && dessert_fix == 0 && (dessert_menu[0][1] == 1 || dessert_menu[1][1] == 1 || dessert_menu[2][1] == 1 || dessert_menu[3][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[9] == 1 && achar_fix == 1 && achar_menu[0][1] == 0 && achar_menu[1][1] == 0 && achar_menu[2][1] == 0)
	{
		if (mx > 32 && mx < 315 && my > 280 && my < 475)
		{
			flag_achar = 0;
		}
		else if (mx > 365 && mx < 655 && my > 285 && my < 475)
		{
			flag_achar = 1;
		}
		else if (mx > 705 && mx < 980 && my > 285 && my < 475)
		{
			flag_achar = 2;
		}
		else
		{
			flag_achar = 5;
		}
	}
	else if (Recipe_sub[9] == 1 && achar_fix == 0 && (achar_menu[0][1] == 1 || achar_menu[1][1] == 1 || achar_menu[2][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (Recipe_sub[8] == 1 && pitha_fix == 1 && pitha_menu[0][1] == 0 && pitha_menu[1][1] == 0 && pitha_menu[1][1] == 0)
	{
		if (mx > 32 && mx < 315 && my > 280 && my < 475)
		{
			flag_pitha = 0;
		}
		else if (mx > 365 && mx < 655 && my > 285 && my < 475)
		{
			flag_pitha = 1;
		}
		else if (mx > 705 && mx < 980 && my > 285 && my < 475)
		{
			flag_pitha = 2;
		}
		else
		{
			flag_pitha = 5;
		}
	}
	else if (Recipe_sub[8] == 1 && pitha_fix == 0 && (pitha_menu[0][1] == 1 || pitha_menu[1][1] == 1 || pitha_menu[1][1] == 1))
	{
		ingre_hover(mx, my);
	}
	else if (current_page == 7)
	{
		if (mx > 35 && mx < 330 && my > 280 && my < 475)
		{
			flag_tribal = 0;
		}
		else if (mx > 413 && mx < 711 && my > 285 && my < 475)
		{
			flag_tribal = 1;
		}
		else if (mx > 792 && mx < 1086 && my > 285 && my < 475)
		{
			flag_tribal = 2;
		}
		else
		{
			flag_tribal = 5;
		}
	}
}
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		if (current_page == 1 && submenu_page == 0)
		{
			if ((mx > 320 && mx < 550) && (my > 390 && my < 530))
			{
				Menu_option = 1;
				printf("Menu_option %d\n", Menu_option);
				submenu_page = 1;
				printf("submenu_page %d\n", submenu_page);
				printf("current page %d", current_page);
				// printf("x = %d, y= %d\n", mx, my);
				// printf("%d\n", Menu_option);
			}
			// else if ((my < 535 && my > 390) && (mx > 470 && mx < 710))
			// {
			// 	Menu_option = 2;
			// 	printf("Menu_option %d\n", Menu_option);
			// 	// printf("x = %d, y= %d\n", mx, my);
			// 	// printf("%d\n", Menu_option);
			// }
			// }
			// if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			// {
			// place your codes here
			else if ((mx> 620 && mx< 860) && (my > 385 && my < 525))
			{
				Menu_option = 2;
				current_page = 4;
				match_fav();
				filein_fav();
				printf("Menu_option %d\n", Menu_option);
				// printf("x = %d, y= %d\n", mx, my);
				// printf("%d\n", Menu_option);
			}
			// }
			// if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			// {
			// place your codes here
			else if ((mx> 190 && mx< 420) && (my > 150 && my < 285))
			{
				current_page = 6;
				match_grocery();
				filein_match();

				// int j;
				// for (j = 0; j < k; j++)
				// {
				// 	printf("%d %d\n", j + 1, ingre_num[j]);
				// }
				// printf("x = %d, y= %d\n", mx, my);
				// printf("%d\n", Menu_option);
			}
			else if ((mx> 475 && mx< 705) && (my > 150 && my < 285))
			{
				current_page = 5;
				l = rand() % 10;
				// printf("x = %d, y= %d\n", mx, my);
				// printf("%d\n", Menu_option);
			}
			else if ((mx > 760 && mx < 990) && (my > 150 && my < 285))
			{
				Menu_option = 5;
				current_page = 7;
				printf("Menu_option %d\n", Menu_option);
				// printf("x = %d, y= %d\n", mx, my);
				// printf("%d\n", Menu_option);
			}
			else if (mx > 980 && mx < 1045 && my > 600 && my < 665)
			{
				current_page = 8;
			}
			else if(mx>1133 && mx<1186 && my>605 && my<660)
			{
				exit(1);
			}
		}
		else if (current_page == 1 && submenu_page == 1)
		{
			// if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			// {
			if (mx > 115 && mx < 360 && my > 328 && my < 490)
			{
				submenu = 1;
				Recipe_sub[0] = 1;
				current_page = 2;
				for (int i = 1; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
				bengali_fix = 1;
				printf("submenu %d\n", submenu);
				printf("current page %d", current_page);
			}
			else if (mx > 450 && mx < 695 && my > 328 && my < 490)
			{
				submenu = 2;
				current_page = 2;
				Recipe_sub[1] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 1)
					{
						Recipe_sub[i] = 0;
					}
				}
				kebab_fix = 1;
				printf("submenu %d\n", submenu);
				printf("current page %d", current_page);
			}
			else if (mx > 795 && mx < 1030 && my > 328 && my < 490)
			{
				submenu = 3;
				current_page = 2;
				Recipe_sub[2] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 2)
					{
						Recipe_sub[i] = 0;
					}
				}
				biryani_fix = 1;
			}
			else if (mx > 280 && mx < 527 && my > 80 && my < 245)
			{
				submenu = 4;
				current_page = 2;
				Recipe_sub[3] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 3)
					{
						Recipe_sub[i] = 0;
					}
				}
				salad_fix = 1;
				printf("submenu %d\n", submenu);
				printf("current page %d", current_page);
			}
			else if (mx > 620 && mx < 865 && my > 80 && my < 240)
			{
				submenu = 5;
				current_page = 2;
				Recipe_sub[4] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 4)
					{
						Recipe_sub[i] = 0;
					}
				}
				vegetable_fix = 1;
				printf("submenu %d\n", submenu);
				printf("current page %d", current_page);
			}
			else if (mx > 1068 && mx < 1195 && my > 295 && my < 418)
			{
				submenu_page = 2;
				submenu = 6;
				printf("submenu %d\n", submenu);
				printf("submenu_page %d\n", submenu_page);
				// submenu_page=2;
			}
			else if (mx > 10 && mx < 160 && my > 10 && my < 110)
			{
				current_page = 1;
				submenu_page = 0;
			}
			// else
			// {
			// 	submenu = 0;
			// }
		}
		else if (current_page == 1 && submenu_page == 2)
		{
			if (mx > 9 && mx < 137 && my > 309 && my < 440)
			{
				// printf("Process 1\n");
				submenu_page = 1;
				printf("submenu_page %d\n", submenu_page);
				submenu = 0;
				printf("submenu %d\n", submenu);
			}
			else if (mx > 171 && mx < 416 && my > 332 && my < 498)
			{
				// printf("%d\n", submenu);
				submenu = 8;
				current_page = 2;
				Recipe_sub[5] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 5)
					{
						Recipe_sub[i] = 0;
					}
				}
				soup_fix = 1;
				printf("submenu %d\n", submenu);
			}
			else if (mx > 508 && mx < 758 && my > 332 && my < 498)
			{
				// printf("%d\n", submenu);
				submenu = 9;
				current_page = 2;
				Recipe_sub[6] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 6)
					{
						Recipe_sub[i] = 0;
					}
				}
				fast_fix = 1;
				printf("submenu %d\n", submenu);
			}
			else if (mx > 840 && mx < 1090 && my > 331 && my < 498)
			{
				// printf("%d\n", submenu);
				submenu = 10;
				current_page = 2;
				Recipe_sub[7] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 7)
					{
						Recipe_sub[i] = 0;
					}
				}
				dessert_fix = 1;
				printf("submenu %d\n", submenu);
			}
			else if (mx > 329 && mx < 584 && my > 85 && my < 253)
			{
				// printf("%d\n", submenu);
				submenu = 11;
				current_page = 2;
				Recipe_sub[8] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 8)
					{
						Recipe_sub[i] = 0;
					}
				}
				pitha_fix = 1;
				printf("submenu %d\n", submenu);
			}
			else if (mx > 670 && mx < 920 && my > 85 && my < 253)
			{
				// printf("%d\n", submenu);
				submenu = 12;
				current_page = 2;
				Recipe_sub[9] = 1;
				for (int i = 0; i < 10; i++)
				{
					if (i != 9)
					{
						Recipe_sub[i] = 0;
					}
				}
				achar_fix = 1;
				printf("submenu %d\n", submenu);
			}
			else if (mx > 10 && mx < 160 && my > 10 && my < 110)
			{
				current_page = 1;
				submenu_page = 0;
			}
		}
		else if (current_page == 2 && submenu_page == 1 && Recipe_sub[0] == 1 && bengali_fix == 1)
		{
			printf("Working 1 \n");
			if (mx > 30 && mx < 290 && my > 420 && my < 610)
			{
				bengali_menu[0][0] = 1;
				for (int i = 1; i < 5; i++)
				{
					bengali_menu[i][0] = 0;
				}
				i_bengali = 0;
				bengali_fix = 0;
			}
			else if (mx > 385 && mx < 645 && my > 420 && my < 610)
			{
				bengali_menu[1][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 1)
					{
						bengali_menu[i][0] = 0;
					}
				}
				i_bengali = 0;
				bengali_fix = 0;
			}
			else if (mx > 735 && mx < 998 && my > 420 && my < 610)
			{
				bengali_menu[2][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 2)
					{
						bengali_menu[i][0] = 0;
					}
				}
				i_bengali = 0;
				bengali_fix = 0;
			}
			else if (mx > 218 && mx < 483 && my > 115 && my < 300)
			{
				bengali_menu[3][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 3)
					{
						bengali_menu[i][0] = 0;
					}
				}
				i_bengali = 0;
				bengali_fix = 0;
			}
			else if (mx > 580 && mx < 840 && my > 115 && my < 300)
			{
				bengali_menu[4][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 4)
					{
						bengali_menu[i][0] = 0;
					}
				}
				i_bengali = 0;
				bengali_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 1;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 0 && bengali_menu[0][i_bengali] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_bengali == 0)
				{
					bengali_fix = 1;
				}
				else
				{
					bengali_menu[0][i_bengali--] = 0;
					bengali_menu[0][i_bengali] = 1;
				}
				if (bengali_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_bengali < 4)
				{
					bengali_menu[0][i_bengali++] = 0;
					bengali_menu[0][i_bengali] = 1;
				}
				else
				{
					bengali_menu[0][i_bengali] = 1;
				}
				if (bengali_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						bengali_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 0);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 0 && bengali_menu[1][i_bengali] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_bengali == 0)
				{
					bengali_fix = 1;
				}
				else
				{
					bengali_menu[1][i_bengali--] = 0;
					bengali_menu[1][i_bengali] = 1;
				}
				if (bengali_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_bengali < 4)
				{
					bengali_menu[1][i_bengali++] = 0;
					bengali_menu[1][i_bengali] = 1;
				}
				else
				{
					bengali_menu[1][i_bengali] = 1;
				}
				if (bengali_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						bengali_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 1);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 0 && bengali_menu[2][i_bengali] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_bengali == 0)
				{
					bengali_fix = 1;
				}
				else
				{
					bengali_menu[2][i_bengali--] = 0;
					bengali_menu[2][i_bengali] = 1;
				}
				if (bengali_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_bengali < 4)
				{
					bengali_menu[2][i_bengali++] = 0;
					bengali_menu[2][i_bengali] = 1;
				}
				else
				{
					bengali_menu[2][i_bengali] = 1;
				}
				if (bengali_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						bengali_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 2);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 0 && bengali_menu[3][i_bengali] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_bengali == 0)
				{
					bengali_fix = 1;
				}
				else
				{
					bengali_menu[3][i_bengali--] = 0;
					bengali_menu[3][i_bengali] = 1;
				}
				if (bengali_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_bengali < 4)
				{
					bengali_menu[3][i_bengali++] = 0;
					bengali_menu[3][i_bengali] = 1;
				}
				else
				{
					bengali_menu[3][i_bengali] = 1;
				}
				if (bengali_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						bengali_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 3);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 0 && bengali_menu[4][i_bengali] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_bengali == 0)
				{
					bengali_fix = 1;
				}
				else
				{
					bengali_menu[4][i_bengali--] = 0;
					bengali_menu[4][i_bengali] = 1;
				}
				if (bengali_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_bengali < 4)
				{
					bengali_menu[4][i_bengali++] = 0;
					bengali_menu[4][i_bengali] = 1;
				}
				else
				{
					bengali_menu[4][i_bengali] = 1;
				}
				if (bengali_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						bengali_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 4);
		}
		else if (current_page == 2 && submenu_page == 1 && Recipe_sub[1] == 1 && kebab_fix == 1)
		{
			printf("Working 8 \n");
			if (mx > 30 && mx < 290 && my > 420 && my < 610)
			{
				kebab_menu[0][0] = 1;
				for (int i = 1; i < 5; i++)
				{
					kebab_menu[i][0] = 0;
				};
				kebab_fix = 0;
			}
			else if (mx > 385 && mx < 645 && my > 420 && my < 610)
			{
				kebab_menu[1][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 1)
					{
						kebab_menu[i][0] = 0;
					}
				}
				kebab_fix = 0;
			}
			else if (mx > 735 && mx < 998 && my > 420 && my < 610)
			{
				kebab_menu[2][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 2)
					{
						kebab_menu[i][0] = 0;
					}
				}
				kebab_fix = 0;
			}
			else if (mx > 218 && mx < 483 && my > 115 && my < 300)
			{
				kebab_menu[3][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 3)
					{
						kebab_menu[i][0] = 0;
					}
				}
				kebab_fix = 0;
			}
			else if (mx > 580 && mx < 840 && my > 115 && my < 300)
			{
				kebab_menu[4][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 4)
					{
						kebab_menu[i][0] = 0;
					}
				}
				kebab_fix = 0;
				i_kebab = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 1;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && flag_ingre == 0 && kebab_menu[0][i_kebab] == 1)
		{
			printf("i_kebab %d\n", i_kebab);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_kebab == 0)
				{
					kebab_fix = 1;
				}
				else
				{
					kebab_menu[0][i_kebab--] = 0;
					kebab_menu[0][i_kebab] = 1;
				}
				if (kebab_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_kebab < 4)
				{
					kebab_menu[0][i_kebab++] = 0;
					kebab_menu[0][i_kebab] = 1;
				}
				else
				{
					kebab_menu[0][i_kebab] = 1;
				}
				if (kebab_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						kebab_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 5);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && flag_ingre == 0 && kebab_menu[1][i_kebab] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_kebab == 0)
				{
					kebab_fix = 1;
				}
				else
				{
					kebab_menu[1][i_kebab--] = 0;
					kebab_menu[1][i_kebab] = 1;
				}
				if (kebab_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_kebab < 4)
				{
					kebab_menu[1][i_kebab++] = 0;
					kebab_menu[1][i_kebab] = 1;
				}
				else
				{
					kebab_menu[1][i_kebab] = 1;
				}
				if (kebab_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						kebab_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 6);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && flag_ingre == 0 && kebab_menu[2][i_kebab] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_kebab == 0)
				{
					kebab_fix = 1;
				}
				else
				{
					kebab_menu[2][i_kebab--] = 0;
					kebab_menu[2][i_kebab] = 1;
				}
				if (kebab_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_kebab < 4)
				{
					kebab_menu[2][i_kebab++] = 0;
					kebab_menu[2][i_kebab] = 1;
				}
				else
				{
					kebab_menu[2][i_kebab] = 1;
				}
				if (kebab_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						kebab_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 7);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && flag_ingre == 0 && kebab_menu[3][i_kebab] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_kebab == 0)
				{
					kebab_fix = 1;
				}
				else
				{
					kebab_menu[3][i_kebab--] = 0;
					kebab_menu[3][i_kebab] = 1;
				}
				if (kebab_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_kebab < 4)
				{
					kebab_menu[3][i_kebab++] = 0;
					kebab_menu[3][i_kebab] = 1;
				}
				else
				{
					kebab_menu[3][i_kebab] = 1;
				}
				if (kebab_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						kebab_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 8);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && flag_ingre == 0 && kebab_menu[4][i_kebab] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_kebab == 0)
				{
					kebab_fix = 1;
				}
				else
				{
					kebab_menu[4][i_kebab--] = 0;
					kebab_menu[4][i_kebab] = 1;
				}
				if (kebab_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_kebab < 4)
				{
					kebab_menu[4][i_kebab++] = 0;
					kebab_menu[4][i_kebab] = 1;
				}
				else
				{
					kebab_menu[4][i_kebab] = 1;
				}
				if (kebab_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						kebab_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 9);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && biryani_fix == 1)
		{
			printf("Working 2 \n");
			if (mx > 30 && mx < 290 && my > 420 && my < 610)
			{
				biriyani_menu[0][0] = 1;
				for (int i = 1; i < 5; i++)
				{
					biriyani_menu[i][0] = 0;
				}
				printf("biriyani_menu[0][0] %d\n", biriyani_menu[0][0]);
				biryani_fix = 0;
				printf("biryani_fix %d\n", biryani_fix);
				printf("i_biryani %d\n", i_biryani);
				printf("biryani_index %d\n", biryani_index);
				// printf("x = %d, y= %d\n", mx, my);
			}
			else if (mx > 385 && mx < 645 && my > 420 && my < 610)
			{
				biriyani_menu[1][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 1)
					{
						biriyani_menu[i][0] = 0;
					}
				}
				biryani_fix = 0;
				printf("biriyani_menu[1][0] %d\n", biriyani_menu[1][0]);
				printf("biryani_fix %d\n", biryani_fix);
			}
			else if (mx > 735 && mx < 998 && my > 420 && my < 610)
			{
				biriyani_menu[2][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 2)
					{
						biriyani_menu[i][0] = 0;
					}
				}
				biryani_fix = 0;
				printf("biriyani_menu[2][0] %d\n", biriyani_menu[2][0]);
				printf("biryani_fix %d\n", biryani_fix);
			}
			else if (mx > 218 && mx < 483 && my > 115 && my < 300)
			{
				biriyani_menu[3][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 3)
					{
						biriyani_menu[i][0] = 0;
					}
				}
				biryani_fix = 0;
				printf("biriyani_menu[3][0] %d\n", biriyani_menu[3][0]);
				printf("biryani_fix %d\n", biryani_fix);
			}
			else if (mx > 580 && mx < 840 && my > 115 && my < 300)
			{
				biriyani_menu[4][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 4)
					{
						biriyani_menu[i][0] = 0;
					}
				}
				biryani_fix = 0;
				printf("biriyani_menu[4][0] %d\n", biriyani_menu[4][0]);
				printf("biryani_fix %d\n", biryani_fix);
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 1;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && flag_ingre == 0 && biriyani_menu[0][i_biryani] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				printf("100\n");
				if (i_biryani == 0)
				{
					biryani_fix = 1;
					printf("biryani_fix %d\n", biryani_fix);
				}
				else
				{
					biriyani_menu[0][i_biryani--] = 0;
					biriyani_menu[0][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				if (biriyani_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_biryani < 4)
				{
					biriyani_menu[0][i_biryani++] = 0;
					biriyani_menu[0][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				else
				{
					biriyani_menu[0][i_biryani] = 1;
				}
				if (biriyani_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						biriyani_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 10);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && flag_ingre == 0 && biriyani_menu[1][i_biryani] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				printf("100\n");
				if (i_biryani == 0)
				{
					biryani_fix = 1;
					printf("biryani_fix %d\n", biryani_fix);
				}
				else
				{
					biriyani_menu[1][i_biryani--] = 0;
					biriyani_menu[1][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				if (biriyani_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_biryani < 4)
				{
					biriyani_menu[1][i_biryani++] = 0;
					biriyani_menu[1][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				else
				{
					biriyani_menu[1][i_biryani] = 1;
				}
				if (biriyani_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						biriyani_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 11);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && flag_ingre == 0 && biriyani_menu[2][i_biryani] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				printf("100\n");
				if (i_biryani == 0)
				{
					biryani_fix = 1;
					printf("biryani_fix %d\n", biryani_fix);
				}
				else
				{
					biriyani_menu[2][i_biryani--] = 0;
					biriyani_menu[2][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				if (biriyani_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_biryani < 4)
				{
					biriyani_menu[2][i_biryani++] = 0;
					biriyani_menu[2][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				else
				{
					biriyani_menu[2][i_biryani] = 1;
				}
				if (biriyani_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						biriyani_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 12);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && flag_ingre == 0 && biriyani_menu[3][i_biryani] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				printf("100\n");
				if (i_biryani == 0)
				{
					biryani_fix = 1;
					printf("biryani_fix %d\n", biryani_fix);
				}
				else
				{
					biriyani_menu[3][i_biryani--] = 0;
					biriyani_menu[3][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				if (biriyani_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_biryani < 4)
				{
					biriyani_menu[3][i_biryani++] = 0;
					biriyani_menu[3][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				else
				{
					biriyani_menu[3][i_biryani] = 1;
				}
				if (biriyani_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						biriyani_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 13);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && flag_ingre == 0 && biriyani_menu[4][i_biryani] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				printf("4 %d", i_biryani);
				if (i_biryani == 0)
				{
					biryani_fix = 1;
					printf("biryani_fix %d\n", biryani_fix);
				}
				else
				{
					biriyani_menu[4][i_biryani--] = 0;
					biriyani_menu[4][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				if (biriyani_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_biryani < 4)
				{
					biriyani_menu[4][i_biryani++] = 0;
					biriyani_menu[4][i_biryani] = 1;
					printf("%d\n", i_biryani);
				}
				else
				{
					biriyani_menu[4][i_biryani] = 1;
				}
				if (biriyani_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						biriyani_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 14);
		}
		else if (current_page == 2 && submenu == 4 && Recipe_sub[3] == 1 && salad_fix == 1)
		{
			printf("Working 9 \n");
			if (mx > 32 && mx < 315 && my > 280 && my < 476)
			{
				salad_menu[0][0] = 1;
				for (int i = 1; i < 3; i++)
				{
					salad_menu[i][0] = 0;
				};
				salad_fix = 0;
			}
			else if (mx > 365 && mx < 655 && my > 285 && my < 480)
			{
				salad_menu[1][0] = 1;
				for (int i = 0; i < 3; i++)
				{
					if (i != 1)
					{
						salad_menu[i][0] = 0;
					}
				}
				salad_fix = 0;
			}
			else if (mx > 705 && mx < 980 && my > 285 && my < 480)
			{
				salad_menu[2][0] = 1;
				for (int i = 0; i < 3; i++)
				{
					if (i != 2)
					{
						salad_menu[i][0] = 0;
					}
				}
				salad_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 1;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 4 && Recipe_sub[3] == 1 && flag_ingre == 0 && salad_menu[0][i_salad] == 1)
		{
			printf("i_salad %d\n", i_salad);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_salad == 0)
				{
					salad_fix = 1;
				}
				else
				{
					salad_menu[0][i_salad--] = 0;
					salad_menu[0][i_salad] = 1;
				}
				if (salad_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_salad < 4)
				{
					salad_menu[0][i_salad++] = 0;
					salad_menu[0][i_salad] = 1;
				}
				else
				{
					salad_menu[0][i_salad] = 1;
				}
				if (salad_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				salad_fix = 1;
				i_salad = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						salad_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 15);
		}
		else if (current_page == 2 && submenu == 4 && Recipe_sub[3] == 1 && flag_ingre == 0 && salad_menu[1][i_salad] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_salad == 0)
				{
					salad_fix = 1;
				}
				else
				{
					salad_menu[1][i_salad--] = 0;
					salad_menu[1][i_salad] = 1;
				}
				if (salad_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_salad < 4)
				{
					salad_menu[1][i_salad++] = 0;
					salad_menu[1][i_salad] = 1;
				}
				else
				{
					salad_menu[1][i_salad] = 1;
				}
				if (salad_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				salad_fix = 1;
				i_salad = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						salad_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 16);
		}
		else if (current_page == 2 && submenu == 4 && Recipe_sub[3] == 1 && flag_ingre == 0 && salad_menu[2][i_salad] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_salad == 0)
				{
					salad_fix = 1;
				}
				else
				{
					salad_menu[2][i_salad--] = 0;
					salad_menu[2][i_salad] = 1;
				}
				if (salad_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_salad < 4)
				{
					salad_menu[2][i_salad++] = 0;
					salad_menu[2][i_salad] = 1;
				}
				else
				{
					salad_menu[2][i_salad] = 1;
				}
				if (salad_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				salad_fix = 1;
				i_salad = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						salad_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 17);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && vegetable_fix == 1)
		{
			printf("Working 8 \n");
			if (mx > 175 && mx < 465 && my > 400 && my < 610)
			{
				vegetable_menu[0][0] = 1;
				for (int i = 1; i < 5; i++)
				{
					vegetable_menu[i][0] = 0;
				};
				vegetable_fix = 0;
			}
			else if (mx > 585 && mx < 895 && my > 400 && my < 610)
			{
				vegetable_menu[1][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 1)
					{
						vegetable_menu[i][0] = 0;
					}
				}
				vegetable_fix = 0;
			}
			else if (mx > 170 && mx < 480 && my > 110 && my < 310)
			{
				vegetable_menu[2][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 2)
					{
						vegetable_menu[i][0] = 0;
					}
				}
				vegetable_fix = 0;
			}
			else if (mx > 585 && mx < 900 && my > 115 && my < 310)
			{
				vegetable_menu[3][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 3)
					{
						vegetable_menu[i][0] = 0;
					}
				}
				vegetable_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 1;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && flag_ingre == 0 && vegetable_menu[0][i_vegetable] == 1)
		{
			printf("i_fast %d\n", i_vegetable);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_vegetable == 0)
				{
					vegetable_fix = 1;
				}
				else
				{
					vegetable_menu[0][i_vegetable--] = 0;
					vegetable_menu[0][i_vegetable] = 1;
				}
				if (vegetable_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_vegetable < 4)
				{
					vegetable_menu[0][i_vegetable++] = 0;
					vegetable_menu[0][i_vegetable] = 1;
				}
				else
				{
					vegetable_menu[0][i_vegetable] = 1;
				}
				if (vegetable_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						vegetable_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 18);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && flag_ingre == 0 && vegetable_menu[1][i_vegetable] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_vegetable == 0)
				{
					vegetable_fix = 1;
				}
				else
				{
					vegetable_menu[1][i_vegetable--] = 0;
					vegetable_menu[1][i_vegetable] = 1;
				}
				if (vegetable_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_vegetable < 4)
				{
					vegetable_menu[1][i_vegetable++] = 0;
					vegetable_menu[1][i_vegetable] = 1;
				}
				else
				{
					vegetable_menu[1][i_vegetable] = 1;
				}
				if (vegetable_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						vegetable_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 19);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && flag_ingre == 0 && vegetable_menu[2][i_vegetable] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_vegetable == 0)
				{
					vegetable_fix = 1;
				}
				else
				{
					vegetable_menu[2][i_vegetable--] = 0;
					vegetable_menu[2][i_vegetable] = 1;
				}
				if (vegetable_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_vegetable < 4)
				{
					vegetable_menu[2][i_vegetable++] = 0;
					vegetable_menu[2][i_vegetable] = 1;
				}
				else
				{
					vegetable_menu[2][i_vegetable] = 1;
				}
				if (vegetable_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						vegetable_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 20);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && flag_ingre == 0 && vegetable_menu[3][i_vegetable] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_vegetable == 0)
				{
					vegetable_fix = 1;
				}
				else
				{
					vegetable_menu[3][i_vegetable--] = 0;
					vegetable_menu[3][i_vegetable] = 1;
				}
				if (vegetable_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_vegetable < 4)
				{
					vegetable_menu[3][i_vegetable++] = 0;
					vegetable_menu[3][i_vegetable] = 1;
				}
				else
				{
					vegetable_menu[3][i_vegetable] = 1;
				}
				if (vegetable_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						vegetable_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 21);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && fast_fix == 1)
		{
			printf("Working 7 \n");
			if (mx > 30 && mx < 290 && my > 420 && my < 610)
			{
				fast_menu[0][0] = 1;
				for (int i = 1; i < 5; i++)
				{
					fast_menu[i][0] = 0;
				};
				fast_fix = 0;
			}
			else if (mx > 385 && mx < 645 && my > 420 && my < 610)
			{
				fast_menu[1][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 1)
					{
						fast_menu[i][0] = 0;
					}
				}
				fast_fix = 0;
			}
			else if (mx > 735 && mx < 998 && my > 420 && my < 610)
			{
				fast_menu[2][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 2)
					{
						fast_menu[i][0] = 0;
					}
				}
				fast_fix = 0;
			}
			else if (mx > 218 && mx < 483 && my > 115 && my < 300)
			{
				fast_menu[3][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 3)
					{
						fast_menu[i][0] = 0;
					}
				}
				fast_fix = 0;
			}
			else if (mx > 580 && mx < 840 && my > 115 && my < 300)
			{
				fast_menu[4][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 4)
					{
						fast_menu[i][0] = 0;
					}
				}
				fast_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 2;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && flag_ingre == 0 && fast_menu[0][i_fast] == 1)
		{
			printf("i_fast %d\n", i_fast);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_fast == 0)
				{
					fast_fix = 1;
				}
				else
				{
					fast_menu[0][i_fast--] = 0;
					fast_menu[0][i_fast] = 1;
				}
				if (fast_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_fast < 4)
				{
					fast_menu[0][i_fast++] = 0;
					fast_menu[0][i_fast] = 1;
				}
				else
				{
					fast_menu[0][i_fast] = 1;
				}
				if (fast_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						fast_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 26);
			// if(mx>565 && mx<635 && my>5 && my<75)
			// {
			// 	favorite_flag=1;
			// }
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && flag_ingre == 0 && fast_menu[1][i_fast] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_fast == 0)
				{
					fast_fix = 1;
				}
				else
				{
					fast_menu[1][i_fast--] = 0;
					fast_menu[1][i_fast] = 1;
				}
				if (fast_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_fast < 4)
				{
					fast_menu[1][i_fast++] = 0;
					fast_menu[1][i_fast] = 1;
				}
				else
				{
					fast_menu[1][i_fast] = 1;
				}
				if (fast_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						fast_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 27);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && flag_ingre == 0 && fast_menu[2][i_fast] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_fast == 0)
				{
					fast_fix = 1;
				}
				else
				{
					fast_menu[2][i_fast--] = 0;
					fast_menu[2][i_fast] = 1;
				}
				if (fast_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_fast < 4)
				{
					fast_menu[2][i_fast++] = 0;
					fast_menu[2][i_fast] = 1;
				}
				else
				{
					fast_menu[2][i_fast] = 1;
				}
				if (fast_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						fast_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 28);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && flag_ingre == 0 && fast_menu[3][i_fast] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_fast == 0)
				{
					fast_fix = 1;
				}
				else
				{
					fast_menu[3][i_fast--] = 0;
					fast_menu[3][i_fast] = 1;
				}
				if (fast_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_fast < 4)
				{
					fast_menu[3][i_fast++] = 0;
					fast_menu[3][i_fast] = 1;
				}
				else
				{
					fast_menu[3][i_fast] = 1;
				}
				if (fast_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						fast_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 29);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && flag_ingre == 0 && fast_menu[4][i_fast] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_fast == 0)
				{
					fast_fix = 1;
				}
				else
				{
					fast_menu[4][i_fast--] = 0;
					fast_menu[4][i_fast] = 1;
				}
				if (fast_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_fast < 4)
				{
					fast_menu[4][i_fast++] = 0;
					fast_menu[4][i_fast] = 1;
				}
				else
				{
					fast_menu[4][i_fast] = 1;
				}
				if (fast_menu[4][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						fast_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 30);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && soup_fix == 1)
		{
			printf("Working 8 \n");
			if (mx > 175 && mx < 465 && my > 400 && my < 610)
			{
				soup_menu[0][0] = 1;
				for (int i = 1; i < 5; i++)
				{
					soup_menu[i][0] = 0;
				};
				soup_fix = 0;
			}
			else if (mx > 585 && mx < 895 && my > 400 && my < 610)
			{
				soup_menu[1][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 1)
					{
						soup_menu[i][0] = 0;
					}
				}
				soup_fix = 0;
			}
			else if (mx > 170 && mx < 480 && my > 110 && my < 310)
			{
				soup_menu[2][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 2)
					{
						soup_menu[i][0] = 0;
					}
				}
				soup_fix = 0;
			}
			else if (mx > 585 && mx < 900 && my > 115 && my < 310)
			{
				soup_menu[3][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 3)
					{
						soup_menu[i][0] = 0;
					}
				}
				soup_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 2;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && flag_ingre == 0 && soup_menu[0][i_soup] == 1)
		{
			printf("i_fast %d\n", i_soup);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_soup == 0)
				{
					soup_fix = 1;
				}
				else
				{
					soup_menu[0][i_soup--] = 0;
					soup_menu[0][i_soup] = 1;
				}
				if (soup_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_soup < 4)
				{
					soup_menu[0][i_soup++] = 0;
					soup_menu[0][i_soup] = 1;
				}
				else
				{
					soup_menu[0][i_soup] = 1;
				}
				if (soup_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						soup_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 22);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && flag_ingre == 0 && soup_menu[1][i_soup] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_soup == 0)
				{
					soup_fix = 1;
				}
				else
				{
					soup_menu[1][i_soup--] = 0;
					soup_menu[1][i_soup] = 1;
				}
				if (soup_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_soup < 4)
				{
					soup_menu[1][i_soup++] = 0;
					soup_menu[1][i_soup] = 1;
				}
				else
				{
					soup_menu[1][i_soup] = 1;
				}
				if (soup_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						soup_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 23);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && flag_ingre == 0 && soup_menu[2][i_soup] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_soup == 0)
				{
					soup_fix = 1;
				}
				else
				{
					soup_menu[2][i_soup--] = 0;
					soup_menu[2][i_soup] = 1;
				}
				if (soup_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_soup < 4)
				{
					soup_menu[2][i_soup++] = 0;
					soup_menu[2][i_soup] = 1;
				}
				else
				{
					soup_menu[2][i_soup] = 1;
				}
				if (soup_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						soup_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 24);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && flag_ingre == 0 && soup_menu[3][i_soup] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_soup == 0)
				{
					soup_fix = 1;
				}
				else
				{
					soup_menu[3][i_soup--] = 0;
					soup_menu[3][i_soup] = 1;
				}
				if (soup_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_soup < 4)
				{
					soup_menu[3][i_soup++] = 0;
					soup_menu[3][i_soup] = 1;
				}
				else
				{
					soup_menu[3][i_soup] = 1;
				}
				if (soup_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						soup_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 25);
		}
		else if (current_page == 2 && submenu == 12 && Recipe_sub[9] == 1 && achar_fix == 1)
		{
			printf("Working 9 \n");
			if (mx > 32 && mx < 315 && my > 280 && my < 476)
			{
				achar_menu[0][0] = 1;
				for (int i = 1; i < 3; i++)
				{
					achar_menu[i][0] = 0;
				};
				achar_fix = 0;
			}
			else if (mx > 365 && mx < 655 && my > 285 && my < 480)
			{
				achar_menu[1][0] = 1;
				for (int i = 0; i < 3; i++)
				{
					if (i != 1)
					{
						achar_menu[i][0] = 0;
					}
				}
				achar_fix = 0;
			}
			else if (mx > 705 && mx < 980 && my > 285 && my < 480)
			{
				achar_menu[2][0] = 1;
				for (int i = 0; i < 3; i++)
				{
					if (i != 2)
					{
						achar_menu[i][0] = 0;
					}
				}
				achar_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 2;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 12 && Recipe_sub[9] == 1 && flag_ingre == 0 && achar_menu[0][i_achar] == 1)
		{
			printf("i_achar %d\n", i_achar);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_achar == 0)
				{
					achar_fix = 1;
				}
				else
				{
					achar_menu[0][i_achar--] = 0;
					achar_menu[0][i_achar] = 1;
				}
				if (achar_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_achar < 4)
				{
					achar_menu[0][i_achar++] = 0;
					achar_menu[0][i_achar] = 1;
				}
				else
				{
					achar_menu[0][i_achar] = 1;
				}
				if (achar_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				achar_fix = 1;
				i_achar = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						achar_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 38);
		}
		else if (current_page == 2 && submenu == 12 && Recipe_sub[9] == 1 && flag_ingre == 0 && achar_menu[1][i_achar] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_achar == 0)
				{
					achar_fix = 1;
				}
				else
				{
					achar_menu[1][i_achar--] = 0;
					achar_menu[1][i_achar] = 1;
				}
				if (achar_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_achar < 4)
				{
					achar_menu[1][i_achar++] = 0;
					achar_menu[1][i_achar] = 1;
				}
				else
				{
					achar_menu[1][i_achar] = 1;
				}
				if (achar_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				achar_fix = 1;
				i_achar = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						achar_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 39);
		}
		else if (current_page == 2 && submenu == 12 && Recipe_sub[9] == 1 && flag_ingre == 0 && achar_menu[2][i_achar] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_achar == 0)
				{
					achar_fix = 1;
				}
				else
				{
					achar_menu[2][i_achar--] = 0;
					achar_menu[2][i_achar] = 1;
				}
				if (achar_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_achar < 4)
				{
					achar_menu[2][i_achar++] = 0;
					achar_menu[2][i_achar] = 1;
				}
				else
				{
					achar_menu[2][i_achar] = 1;
				}
				if (achar_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				achar_fix = 1;
				i_achar = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						achar_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 40);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && dessert_fix == 1)
		{
			printf("Working 8 \n");
			if (mx > 185 && mx < 470 && my > 395 && my < 585)
			{
				dessert_menu[0][0] = 1;
				for (int i = 1; i < 5; i++)
				{
					dessert_menu[i][0] = 0;
				};
				dessert_fix = 0;
			}
			else if (mx > 595 && mx < 880 && my > 395 && my < 585)
			{
				dessert_menu[1][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 1)
					{
						dessert_menu[i][0] = 0;
					}
				}
				dessert_fix = 0;
			}
			else if (mx > 185 && mx < 470 && my > 105 && my < 300)
			{
				dessert_menu[2][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 2)
					{
						dessert_menu[i][0] = 0;
					}
				}
				dessert_fix = 0;
			}
			else if (mx > 605 && mx < 890 && my > 105 && my < 300)
			{
				dessert_menu[3][0] = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i != 3)
					{
						dessert_menu[i][0] = 0;
					}
				}
				dessert_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 2;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && flag_ingre == 0 && dessert_menu[0][i_dessert] == 1)
		{
			printf("i_fast %d\n", i_dessert);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_dessert == 0)
				{
					dessert_fix = 1;
				}
				else
				{
					dessert_menu[0][i_dessert--] = 0;
					dessert_menu[0][i_dessert] = 1;
				}
				if (dessert_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_dessert < 4)
				{
					dessert_menu[0][i_dessert++] = 0;
					dessert_menu[0][i_dessert] = 1;
				}
				else
				{
					dessert_menu[0][i_dessert] = 1;
				}
				if (dessert_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						dessert_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 31);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && flag_ingre == 0 && dessert_menu[1][i_dessert] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_dessert == 0)
				{
					dessert_fix = 1;
				}
				else
				{
					dessert_menu[1][i_dessert--] = 0;
					dessert_menu[1][i_dessert] = 1;
				}
				if (dessert_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_dessert < 4)
				{
					dessert_menu[1][i_dessert++] = 0;
					dessert_menu[1][i_dessert] = 1;
				}
				else
				{
					dessert_menu[1][i_dessert] = 1;
				}
				if (dessert_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						dessert_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 32);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && flag_ingre == 0 && dessert_menu[2][i_dessert] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_dessert == 0)
				{
					dessert_fix = 1;
				}
				else
				{
					dessert_menu[2][i_dessert--] = 0;
					dessert_menu[2][i_dessert] = 1;
				}
				if (dessert_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_dessert < 4)
				{
					dessert_menu[2][i_dessert++] = 0;
					dessert_menu[2][i_dessert] = 1;
				}
				else
				{
					dessert_menu[2][i_dessert] = 1;
				}
				if (dessert_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						dessert_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 33);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && flag_ingre == 0 && dessert_menu[3][i_dessert] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_dessert == 0)
				{
					dessert_fix = 1;
				}
				else
				{
					dessert_menu[3][i_dessert--] = 0;
					dessert_menu[3][i_dessert] = 1;
				}
				if (dessert_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_dessert < 4)
				{
					dessert_menu[3][i_dessert++] = 0;
					dessert_menu[3][i_dessert] = 1;
				}
				else
				{
					dessert_menu[3][i_dessert] = 1;
				}
				if (dessert_menu[3][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						dessert_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 34);
		}
		else if (current_page == 2 && submenu == 11 && Recipe_sub[8] == 1 && pitha_fix == 1)
		{
			printf("Working 9 \n");
			if (mx > 32 && mx < 315 && my > 280 && my < 476)
			{
				pitha_menu[0][0] = 1;
				for (int i = 1; i < 3; i++)
				{
					pitha_menu[i][0] = 0;
				};
				pitha_fix = 0;
			}
			else if (mx > 365 && mx < 655 && my > 285 && my < 480)
			{
				pitha_menu[1][0] = 1;
				for (int i = 0; i < 3; i++)
				{
					if (i != 1)
					{
						pitha_menu[i][0] = 0;
					}
				}
				pitha_fix = 0;
			}
			else if (mx > 705 && mx < 980 && my > 285 && my < 480)
			{
				pitha_menu[2][0] = 1;
				for (int i = 0; i < 3; i++)
				{
					if (i != 2)
					{
						pitha_menu[i][0] = 0;
					}
				}
				pitha_fix = 0;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 2;
				for (int i = 0; i < 10; i++)
				{
					Recipe_sub[i] = 0;
				}
			}
		}
		else if (current_page == 2 && submenu == 11 && Recipe_sub[8] == 1 && flag_ingre == 0 && pitha_menu[0][i_pitha] == 1)
		{
			printf("i_pitha %d\n", i_pitha);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_pitha == 0)
				{
					pitha_fix = 1;
				}
				else
				{
					pitha_menu[0][i_pitha--] = 0;
					pitha_menu[0][i_pitha] = 1;
				}
				if (pitha_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_pitha < 4)
				{
					pitha_menu[0][i_pitha++] = 0;
					pitha_menu[0][i_pitha] = 1;
				}
				else
				{
					pitha_menu[0][i_pitha] = 1;
				}
				if (pitha_menu[0][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				pitha_fix = 1;
				i_pitha = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						pitha_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 35);
		}
		else if (current_page == 2 && submenu == 11 && Recipe_sub[8] == 1 && flag_ingre == 0 && pitha_menu[1][i_pitha] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_pitha == 0)
				{
					pitha_fix = 1;
				}
				else
				{
					pitha_menu[1][i_pitha--] = 0;
					pitha_menu[1][i_pitha] = 1;
				}
				if (pitha_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				printf("001");
				if (i_pitha < 4)
				{
					pitha_menu[1][i_pitha++] = 0;
					pitha_menu[1][i_pitha] = 1;
				}
				else
				{
					pitha_menu[1][i_pitha] = 1;
				}
				if (pitha_menu[1][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				pitha_fix = 1;
				i_pitha = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						pitha_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 36);
		}
		else if (current_page == 2 && submenu == 11 && Recipe_sub[8] == 1 && flag_ingre == 0 && pitha_menu[2][i_pitha] == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				if (i_pitha == 0)
				{
					pitha_fix = 1;
				}
				else
				{
					pitha_menu[2][i_pitha--] = 0;
					pitha_menu[2][i_pitha] = 1;
				}
				if (pitha_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				if (i_pitha < 4)
				{
					pitha_menu[2][i_pitha++] = 0;
					pitha_menu[2][i_pitha] = 1;
				}
				else
				{
					pitha_menu[2][i_pitha] = 1;
				}
				if (pitha_menu[2][1] == 1)
				{
					flag_ingre = 1;
				}
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				pitha_fix = 1;
				i_pitha = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						pitha_menu[i][j] = 0;
					}
				}
			}
			fav(mx, my, 37);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 1 && bengali_menu[0][1] == 1)
		{
			ingre_click(mx, my, 0);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_bengali = 0;
				bengali_menu[0][1] = 0;
				bengali_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_bengali = 2;
				bengali_menu[0][1] = 0;
				bengali_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				flag_ingre = 0;
				bengali_menu[0][1] = 0;
			}
			fav(mx, my, 0);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 1 && bengali_menu[1][1] == 1)
		{
			ingre_click(mx, my, 1);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_bengali = 0;
				bengali_menu[1][1] = 0;
				bengali_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_bengali = 2;
				bengali_menu[1][1] = 0;
				bengali_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				flag_ingre = 0;
				bengali_menu[1][1] = 0;
			}
			fav(mx, my, 1);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 1 && bengali_menu[2][1] == 1)
		{
			ingre_click(mx, my, 2);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_bengali = 0;
				bengali_menu[2][1] = 0;
				bengali_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_bengali = 2;
				bengali_menu[2][1] = 0;
				bengali_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				flag_ingre = 0;
				bengali_menu[2][1] = 0;
			}
			fav(mx, my, 2);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 1 && bengali_menu[3][1] == 1)
		{
			ingre_click(mx, my, 3);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_bengali = 0;
				bengali_menu[3][1] = 0;
				bengali_menu[3][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_bengali = 2;
				bengali_menu[3][1] = 0;
				bengali_menu[3][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				flag_ingre = 0;
				bengali_menu[3][1] = 0;
			}
			fav(mx, my, 3);
		}
		else if (current_page == 2 && submenu == 1 && Recipe_sub[0] == 1 && bengali_fix == 0 && flag_ingre == 1 && bengali_menu[4][1] == 1)
		{
			ingre_click(mx, my, 4);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_bengali = 0;
				bengali_menu[4][1] = 0;
				bengali_menu[4][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_bengali = 2;
				bengali_menu[4][1] = 0;
				bengali_menu[4][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				bengali_fix = 1;
				i_bengali = 0;
				flag_ingre = 0;
				bengali_menu[4][1] = 0;
			}
			fav(mx, my, 4);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && kebab_fix == 0 && flag_ingre == 1 && kebab_menu[0][1] == 1)
		{
			ingre_click(mx, my, 5);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_kebab = 0;
				kebab_menu[0][1] = 0;
				kebab_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_kebab = 2;
				kebab_menu[0][1] = 0;
				kebab_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				flag_ingre = 0;
				kebab_menu[0][1] = 0;
			}
			fav(mx, my, 5);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && kebab_fix == 0 && flag_ingre == 1 && kebab_menu[1][1] == 1)
		{
			ingre_click(mx, my, 6);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_kebab = 0;
				kebab_menu[1][1] = 0;
				kebab_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_kebab = 2;
				kebab_menu[1][1] = 0;
				kebab_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				flag_ingre = 0;
				kebab_menu[1][1] = 0;
			}
			fav(mx, my, 6);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && kebab_fix == 0 && flag_ingre == 1 && kebab_menu[2][1] == 1)
		{
			ingre_click(mx, my, 7);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_kebab = 0;
				kebab_menu[2][1] = 0;
				kebab_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_kebab = 2;
				kebab_menu[2][1] = 0;
				kebab_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				flag_ingre = 0;
				kebab_menu[2][1] = 0;
			}
			fav(mx, my, 7);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && kebab_fix == 0 && flag_ingre == 1 && kebab_menu[3][1] == 1)
		{
			ingre_click(mx, my, 8);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_kebab = 0;
				kebab_menu[3][1] = 0;
				kebab_menu[3][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_kebab = 2;
				kebab_menu[3][1] = 0;
				kebab_menu[3][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				flag_ingre = 0;
				kebab_menu[3][1] = 0;
			}
			fav(mx, my, 8);
		}
		else if (current_page == 2 && submenu == 2 && Recipe_sub[1] == 1 && kebab_fix == 0 && flag_ingre == 1 && kebab_menu[4][1] == 1)
		{
			ingre_click(mx, my, 9);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_kebab = 0;
				kebab_menu[4][1] = 0;
				kebab_menu[4][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_kebab = 2;
				kebab_menu[4][1] = 0;
				kebab_menu[4][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				kebab_fix = 1;
				i_kebab = 0;
				flag_ingre = 0;
				kebab_menu[4][1] = 0;
			}
			fav(mx, my, 9);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && biryani_fix == 0 && flag_ingre == 1 && biriyani_menu[0][1] == 1)
		{
			ingre_click(mx, my, 10);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_biryani = 0;
				biriyani_menu[0][1] = 0;
				biriyani_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_biryani = 2;
				biriyani_menu[0][1] = 0;
				biriyani_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				flag_ingre = 0;
				biriyani_menu[0][1] = 0;
			}
			fav(mx, my, 10);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && biryani_fix == 0 && flag_ingre == 1 && biriyani_menu[1][1] == 1)
		{
			ingre_click(mx, my, 11);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_biryani = 0;
				biriyani_menu[1][1] = 0;
				biriyani_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_biryani = 2;
				biriyani_menu[1][1] = 0;
				biriyani_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				flag_ingre = 0;
				biriyani_menu[1][1] = 0;
			}
			fav(mx, my, 11);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && biryani_fix == 0 && flag_ingre == 1 && biriyani_menu[2][1] == 1)
		{
			ingre_click(mx, my, 12);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_biryani = 0;
				biriyani_menu[2][1] = 0;
				biriyani_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_biryani = 2;
				biriyani_menu[2][1] = 0;
				biriyani_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				flag_ingre = 0;
				biriyani_menu[2][1] = 0;
			}
			fav(mx, my, 12);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && biryani_fix == 0 && flag_ingre == 1 && biriyani_menu[3][1] == 1)
		{
			ingre_click(mx, my, 13);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_biryani = 0;
				biriyani_menu[3][1] = 0;
				biriyani_menu[3][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_biryani = 2;
				biriyani_menu[3][1] = 0;
				biriyani_menu[3][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				flag_ingre = 0;
				biriyani_menu[3][1] = 0;
			}
			fav(mx, my, 13);
		}
		else if (current_page == 2 && submenu == 3 && Recipe_sub[2] == 1 && biryani_fix == 0 && flag_ingre == 1 && biriyani_menu[4][1] == 1)
		{
			ingre_click(mx, my, 14);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_biryani = 0;
				biriyani_menu[4][1] = 0;
				biriyani_menu[4][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_biryani = 2;
				biriyani_menu[4][1] = 0;
				biriyani_menu[4][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				biryani_fix = 1;
				i_biryani = 0;
				flag_ingre = 0;
				biriyani_menu[4][1] = 0;
			}
			fav(mx, my, 14);
		}
		else if (current_page == 2 && submenu == 4 && Recipe_sub[3] == 1 && salad_fix == 0 && flag_ingre == 1 && salad_menu[0][1] == 1)
		{
			ingre_click(mx, my, 15);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_salad = 0;
				salad_menu[0][1] = 0;
				salad_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_salad = 2;
				salad_menu[0][1] = 0;
				salad_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				salad_fix = 1;
				i_salad = 0;
				flag_ingre = 0;
				salad_menu[0][1] = 0;
			}
			fav(mx, my, 15);
		}
		else if (current_page == 2 && submenu == 4 && Recipe_sub[3] == 1 && salad_fix == 0 && flag_ingre == 1 && salad_menu[1][1] == 1)
		{
			ingre_click(mx, my, 16);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_salad = 0;
				salad_menu[1][1] = 0;
				salad_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_salad = 2;
				salad_menu[1][1] = 0;
				salad_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				salad_fix = 1;
				i_salad = 0;
				flag_ingre = 0;
				salad_menu[1][1] = 0;
			}
			fav(mx, my, 16);
		}
		else if (current_page == 2 && submenu == 4 && Recipe_sub[3] == 1 && salad_fix == 0 && flag_ingre == 1 && salad_menu[2][1] == 1)
		{
			ingre_click(mx, my, 17);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_salad = 0;
				salad_menu[2][1] = 0;
				salad_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_salad = 2;
				salad_menu[2][1] = 0;
				salad_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				salad_fix = 1;
				i_salad = 0;
				flag_ingre = 0;
				salad_menu[2][1] = 0;
			}
			fav(mx, my, 17);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && vegetable_fix == 0 && flag_ingre == 1 && vegetable_menu[0][1] == 1)
		{
			ingre_click(mx, my, 18);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_vegetable = 0;
				vegetable_menu[0][1] = 0;
				vegetable_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_vegetable = 2;
				vegetable_menu[0][1] = 0;
				vegetable_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				flag_ingre = 0;
				vegetable_menu[0][1] = 0;
			}
			fav(mx, my, 18);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && vegetable_fix == 0 && flag_ingre == 1 && vegetable_menu[1][1] == 1)
		{
			ingre_click(mx, my, 19);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_vegetable = 0;
				vegetable_menu[1][1] = 0;
				vegetable_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_vegetable = 2;
				vegetable_menu[1][1] = 0;
				vegetable_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				flag_ingre = 0;
				vegetable_menu[1][1] = 0;
			}
			fav(mx, my, 19);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && vegetable_fix == 0 && flag_ingre == 1 && vegetable_menu[2][1] == 1)
		{
			ingre_click(mx, my, 20);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_vegetable = 0;
				vegetable_menu[2][1] = 0;
				vegetable_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_vegetable = 2;
				vegetable_menu[2][1] = 0;
				vegetable_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				flag_ingre = 0;
				vegetable_menu[2][1] = 0;
			}
			fav(mx, my, 20);
		}
		else if (current_page == 2 && submenu == 5 && Recipe_sub[4] == 1 && vegetable_fix == 0 && flag_ingre == 1 && vegetable_menu[3][1] == 1)
		{
			ingre_click(mx, my, 21);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_vegetable = 0;
				vegetable_menu[3][1] = 0;
				vegetable_menu[3][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_vegetable = 2;
				vegetable_menu[3][1] = 0;
				vegetable_menu[3][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				vegetable_fix = 1;
				i_vegetable = 0;
				flag_ingre = 0;
				vegetable_menu[3][1] = 0;
			}
			fav(mx, my, 21);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && soup_fix == 0 && flag_ingre == 1 && soup_menu[0][1] == 1)
		{
			ingre_click(mx, my, 22);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_soup = 0;
				soup_menu[0][1] = 0;
				soup_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_soup = 2;
				soup_menu[0][1] = 0;
				soup_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				flag_ingre = 0;
				soup_menu[0][1] = 0;
			}
			fav(mx, my, 22);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && soup_fix == 0 && flag_ingre == 1 && soup_menu[1][1] == 1)
		{
			ingre_click(mx, my, 23);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_soup = 0;
				soup_menu[1][1] = 0;
				soup_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_soup = 2;
				soup_menu[1][1] = 0;
				soup_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				flag_ingre = 0;
				soup_menu[1][1] = 0;
			}
			fav(mx, my, 23);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && soup_fix == 0 && flag_ingre == 1 && soup_menu[2][1] == 1)
		{
			ingre_click(mx, my, 24);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_soup = 0;
				soup_menu[2][1] = 0;
				soup_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_soup = 2;
				soup_menu[2][1] = 0;
				soup_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				flag_ingre = 0;
				soup_menu[2][1] = 0;
			}
			fav(mx, my, 24);
		}
		else if (current_page == 2 && submenu == 8 && Recipe_sub[5] == 1 && soup_fix == 0 && flag_ingre == 1 && soup_menu[3][1] == 1)
		{
			ingre_click(mx, my, 25);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_soup = 0;
				soup_menu[3][1] = 0;
				soup_menu[3][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_soup = 2;
				soup_menu[3][1] = 0;
				soup_menu[3][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				soup_fix = 1;
				i_soup = 0;
				flag_ingre = 0;
				soup_menu[3][1] = 0;
			}
			fav(mx, my, 25);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && fast_fix == 0 && flag_ingre == 1 && fast_menu[0][1] == 1)
		{
			ingre_click(mx, my, 26);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_fast = 0;
				fast_menu[0][1] = 0;
				fast_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_fast = 2;
				fast_menu[0][1] = 0;
				fast_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				flag_ingre = 0;
				fast_menu[0][1] = 0;
			}
			fav(mx, my, 26);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && fast_fix == 0 && flag_ingre == 1 && fast_menu[1][1] == 1)
		{
			ingre_click(mx, my, 27);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_fast = 0;
				fast_menu[1][1] = 0;
				fast_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_fast = 2;
				fast_menu[1][1] = 0;
				fast_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				flag_ingre = 0;
				fast_menu[1][1] = 0;
			}
			fav(mx, my, 27);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && fast_fix == 0 && flag_ingre == 1 && fast_menu[2][1] == 1)
		{
			ingre_click(mx, my, 28);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_fast = 0;
				fast_menu[2][1] = 0;
				fast_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_fast = 2;
				fast_menu[2][1] = 0;
				fast_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				flag_ingre = 0;
				fast_menu[2][1] = 0;
			}
			fav(mx, my, 28);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && fast_fix == 0 && flag_ingre == 1 && fast_menu[3][1] == 1)
		{
			ingre_click(mx, my, 29);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_fast = 0;
				fast_menu[3][1] = 0;
				fast_menu[3][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_fast = 2;
				fast_menu[3][1] = 0;
				fast_menu[3][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				flag_ingre = 0;
				fast_menu[3][1] = 0;
			}
			fav(mx, my, 29);
		}
		else if (current_page == 2 && submenu == 9 && Recipe_sub[6] == 1 && fast_fix == 0 && flag_ingre == 1 && fast_menu[4][1] == 1)
		{
			ingre_click(mx, my, 30);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_fast = 0;
				fast_menu[4][1] = 0;
				fast_menu[4][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_fast = 2;
				fast_menu[4][1] = 0;
				fast_menu[4][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				fast_fix = 1;
				i_fast = 0;
				flag_ingre = 0;
				fast_menu[4][1] = 0;
			}
			fav(mx, my, 30);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && dessert_fix == 0 && flag_ingre == 1 && dessert_menu[3][1] == 1)
		{
			ingre_click(mx, my, 31);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_dessert = 0;
				dessert_menu[3][1] = 0;
				dessert_menu[3][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_dessert = 2;
				dessert_menu[3][1] = 0;
				dessert_menu[3][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				flag_ingre = 0;
				dessert_menu[3][1] = 0;
			}
			fav(mx, my, 31);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && dessert_fix == 0 && flag_ingre == 1 && dessert_menu[0][1] == 1)
		{
			ingre_click(mx, my, 32);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_dessert = 0;
				dessert_menu[0][1] = 0;
				dessert_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_dessert = 2;
				dessert_menu[0][1] = 0;
				dessert_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				flag_ingre = 0;
				dessert_menu[0][1] = 0;
			}
			fav(mx, my, 32);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && dessert_fix == 0 && flag_ingre == 1 && dessert_menu[1][1] == 1)
		{
			ingre_click(mx, my, 33);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_dessert = 0;
				dessert_menu[1][1] = 0;
				dessert_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_dessert = 2;
				dessert_menu[1][1] = 0;
				dessert_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				flag_ingre = 0;
				dessert_menu[1][1] = 0;
			}
			fav(mx, my, 33);
		}
		else if (current_page == 2 && submenu == 10 && Recipe_sub[7] == 1 && dessert_fix == 0 && flag_ingre == 1 && dessert_menu[2][1] == 1)
		{
			ingre_click(mx, my, 34);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_dessert = 0;
				dessert_menu[2][1] = 0;
				dessert_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_dessert = 2;
				dessert_menu[2][1] = 0;
				dessert_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				dessert_fix = 1;
				i_dessert = 0;
				flag_ingre = 0;
				dessert_menu[2][1] = 0;
			}
			fav(mx, my, 34);
		}
		else if (current_page == 2 && submenu == 11 && Recipe_sub[8] == 1 && pitha_fix == 0 && flag_ingre == 1 && pitha_menu[2][1] == 1)
		{
			ingre_click(mx, my, 35);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_pitha = 0;
				pitha_menu[2][1] = 0;
				pitha_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_pitha = 2;
				pitha_menu[2][1] = 0;
				pitha_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				pitha_fix = 1;
				i_pitha = 0;
				flag_ingre = 0;
				pitha_menu[2][1] = 0;
			}
			fav(mx, my, 35);
		}
		else if (current_page == 2 && submenu == 11 && Recipe_sub[8] == 1 && pitha_fix == 0 && flag_ingre == 1 && pitha_menu[0][1] == 1)
		{
			ingre_click(mx, my, 36);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_pitha = 0;
				pitha_menu[0][1] = 0;
				pitha_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_pitha = 2;
				pitha_menu[0][1] = 0;
				pitha_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				pitha_fix = 1;
				i_pitha = 0;
				flag_ingre = 0;
				pitha_menu[0][1] = 0;
			}
			fav(mx, my, 36);
		}
		else if (current_page == 2 && submenu == 11 && Recipe_sub[8] == 1 && pitha_fix == 0 && flag_ingre == 1 && pitha_menu[1][1] == 1)
		{
			ingre_click(mx, my, 37);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_pitha = 0;
				pitha_menu[1][1] = 0;
				pitha_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_pitha = 2;
				pitha_menu[1][1] = 0;
				pitha_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				pitha_fix = 1;
				i_pitha = 0;
				flag_ingre = 0;
				pitha_menu[1][1] = 0;
			}
			fav(mx, my, 37);
		}
		else if (current_page == 2 && submenu == 12 && Recipe_sub[9] == 1 && achar_fix == 0 && flag_ingre == 1 && achar_menu[1][1] == 1)
		{
			ingre_click(mx, my, 38);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_achar = 0;
				achar_menu[1][1] = 0;
				achar_menu[1][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_achar = 2;
				achar_menu[1][1] = 0;
				achar_menu[1][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				achar_fix = 1;
				i_achar = 0;
				flag_ingre = 0;
				achar_menu[1][1] = 0;
			}
			fav(mx, my, 38);
		}
		else if (current_page == 2 && submenu == 12 && Recipe_sub[9] == 1 && achar_fix == 0 && flag_ingre == 1 && achar_menu[0][1] == 1)
		{
			ingre_click(mx, my, 39);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_achar = 0;
				achar_menu[0][1] = 0;
				achar_menu[0][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_achar = 2;
				achar_menu[0][1] = 0;
				achar_menu[0][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				achar_fix = 1;
				i_achar = 0;
				flag_ingre = 0;
				achar_menu[0][1] = 0;
			}
			fav(mx, my, 39);
		}
		else if (current_page == 2 && submenu == 12 && Recipe_sub[9] == 1 && achar_fix == 0 && flag_ingre == 1 && achar_menu[2][1] == 1)
		{
			ingre_click(mx, my, 40);
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				flag_ingre = 0;
				i_achar = 0;
				achar_menu[2][1] = 0;
				achar_menu[2][0] = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				flag_ingre = 0;
				i_achar = 2;
				achar_menu[2][1] = 0;
				achar_menu[2][2] = 1;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				achar_fix = 1;
				i_achar = 0;
				flag_ingre = 0;
				achar_menu[2][1] = 0;
			}
			fav(mx, my, 40);
		}
		// if (current_page == 0 && mx >= 681 && mx <= 821 && my >= 50 && my <= 110)
		// {
		// 	iu = 0;
		// 	ip = 0;
		// 	user[0] = '\0';
		// 	pass[0] = '\0';
		// 	spass[0] = '\0';
		// 	accButton();
		// }
		// if (nacc == 1 && mx >= 373 && mx <= 625 && my >= 404 && my <= 446)
		// {
		// 	nuser = 1;
		// 	npass = 0;
		// }
		// if (nacc == 1 && mx >= 373 && mx <= 621 && my >= 341 && my <= 387)
		// {
		// 	nuser = 0;
		// 	npass = 1;
		// }
		// if (nacc == 1 && mx >= 378 && mx <= 623 && my >= 255 && my <= 300)
		// {
		// 	accin();
		// 	user[0] = '\0';
		// 	pass[0] = '\0';
		// 	iu = 0;
		// 	ip = 0;
		// }
		if (current_page == 0 && mx >= 147 && mx <= 465 && my >= 419 && my <= 464)
		{
			if (auth == 0 || auth == 2)
			{
				user[0] = '\0';
				pass[0] = '\0';
				spass[0] = '\0';
				auth = -1;
				iu = 0;
				ip = 0;
			}
			nuser = 1;
			npass = 0;
		}
		if (current_page == 0 && mx >= 148 && mx <= 464 && my >= 315 && my <= 365)
		{
			if (auth == 0 || auth == 2)
			{
				user[0] = '\0';
				pass[0] = '\0';
				spass[0] = '\0';
				auth = -1;
				iu = 0;
				ip = 0;
			}
			npass = 1;
			nuser = 0;
		}

		if (current_page == 0 && mx >= 149 && mx <= 464 && my >= 204 && my <= 250 && user[0] != '\0' && pass[0] != '\0') //
		{
			check();
			if (auth == 1)
			{
				auth = -1;
				strcpy(cuser, user);
				user[0] = '\0';
				pass[0] = '\0';
				spass[0] = '\0';
				current_page = 1;
			}
			if (auth == 0 || auth == 2)
			{
				user[0] = '\0';
				pass[0] = '\0';
				spass[0] = '\0';
				auth = -1;
				iu = 0;
				ip = 0;
			}
		}
		else if (current_page == 6 && mx > 1100 && mx < 1200 && my > 575 && my < 675)
		{
			current_page = 1;
			submenu_page = 0;
		}
		else if (current_page == 4 && mx > 1100 && mx < 1200 && my > 575 && my < 675)
		{
			current_page = 1;
			submenu_page = 0;
		}
		else if (current_page == 6 && mx > 1100 && mx < 1200 && my > 575 && my < 675)
		{
			current_page = 1;
			submenu_page = 0;
		}
		else if (current_page == 6 && mx > 1100 && mx < 1200 && my > 480 && my < 560)
		{
			for (int i = 0; i < 11; i++)
			{
				ingre_num[i] = 0;
			}
			for (int i = 0; i < 42; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					ingre_sup[i][j] = 0;
				}
			}
		}
		else if (current_page == 4 && mx > 1100 && mx < 1200 && my > 480 && my < 560)
		{
			for (int i = 0; i < 10; i++)
			{
				fav_num[i] = 0;
			}
			for (int i = 0; i < 42; i++)
			{
				fav_sup[i] = 0;
			}
		}
		else if (current_page == 5 && mx > 1100 && mx < 1200 && my > 575 && my < 675)
		{
			current_page = 1;
			submenu_page = 0;
		}
		else if (current_page == 7 && i_tribal == 0)
		{
			if (mx > 35 && mx < 330 && my > 290 && my < 475)
			{
				i_tribal = 1;
			}
			else if (mx > 413 && mx < 711 && my > 291 && my < 475)
			{
				i_tribal = 4;
			}
			else if (mx > 792 && mx < 1085 && my > 285 && my < 475)
			{
				i_tribal = 7;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 1)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 0;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				i_tribal = 2;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 2)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 1;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				i_tribal = 3;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 3)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 2;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 4)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 0;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				i_tribal = 5;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 5)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 4;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				i_tribal = 6;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 6)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 5;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 7)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 0;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				i_tribal = 8;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 8)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 7;
			}
			else if (mx > 1135 && mx < 1190 && my > 15 && my < 90)
			{
				i_tribal = 9;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 7 && i_tribal == 9)
		{
			if (mx > 15 && mx < 95 && my > 15 && my < 95)
			{
				i_tribal = 8;
			}
			else if (mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				i_tribal = 0;
			}
		}
		else if (current_page == 8)
		{
			if (sound == 1 && about ==0 && mx > 380 && mx < 470 && my > 390 && my < 480)
			{
				sound = 0;
				PlaySound(0, 0, 0);
			}
			else if (sound == 0 && about ==0 && mx > 380 && mx < 470 && my > 390 && my < 480)
			{
				sound = 1;
				if (sound == 1)
					PlaySound("pictures\\Journey_chosic.com_.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else if ( about ==0 && mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 1;
				submenu_page = 0;
			}
			else if((sound == 1|| sound==0) && mx>360 && mx<750 && my>240 && my<360)
			{
				about=1;
			}
			else if ( about ==1 && mx > 1100 && mx < 1180 && my > 575 && my < 655)
			{
				current_page = 8;
				about = 0;
			}
		}
		// else if (current_page == 6)
		// {
		// 	printf("dhukse\n");
		// 	k = 0;
		// 	match_grocery();
		// 	for (int j = 0; j < k; j++)
		// 	{
		// 		printf("%d %d\n", j + 1, ingre_num[j]);
		// 	}
		// }
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		printf("x = %d, y= %d\n", mx, my);
	}
}
void iDrawMenu()
{
	if (current_page == 1 && submenu_page == 0)
	{
		if (Menu_option == 0)
		{
			iShowBMP(0, 0, "pictures\\Menu\\Home_menu.bmp");
		}
		else if (Menu_option == 1)
		{
			iShowBMP(0, 0, "pictures\\Menu\\Home_menu_1.bmp");
		}
		else if (Menu_option == 2)
		{
			iShowBMP(0, 0, "pictures\\Menu\\Home_menu_2.bmp");
		}
		else if (Menu_option == 3)
		{
			iShowBMP(0, 0, "pictures\\Menu\\Home_menu_3.bmp");
		}
		else if (Menu_option == 4)
		{
			iShowBMP(0, 0, "pictures\\Menu\\Home_menu_4.bmp");
		}
		else if (Menu_option == 5)
		{
			iShowBMP(0, 0, "pictures\\Menu\\Home_menu_5.bmp");
		}
		// else if (Menu_option == 6)
		// {
		// 	iShowBMP(0, 0, "pictures\\Menu\\Home_menu_6.bmp");
		// }
	}
}

void iDrawSubMenu()
{
	if (current_page == 1 && submenu_page == 1)
	{
		if (submenu == 0)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_1.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		if (submenu == 1)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_2.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 2)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_3.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 3)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_4.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 4)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_5.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 5)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_6.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
	}
	else if (current_page == 1 && submenu_page == 2)
	{
		if (submenu == 6)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_7.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 7)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_1.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 8)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_8.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 9)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_9.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 10)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_10.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 11)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_11.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
		else if (submenu == 12)
		{
			iShowBMP(0, 0, "pictures\\RecipeSub\\Recipe_sub_menu_12.bmp");
			iShowBMP2(0, 0, "pictures\\Jump\\main.bmp", 0);
		}
	}
}
void biryani()
{
	if (Recipe_sub[2] == 1)
	{
		if (biryani_fix == 0)
		{
			if (biriyani_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Chicken_biryani_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(10);
				// printf("something\n");
			}
			else if (biriyani_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Kacchi_biryani_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(11);
				// printf("Something else\n");
			}
			else if (biriyani_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Beef_tehari_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(12);
			}
			else if (biriyani_menu[3][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Shahi_beef_biryani_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(13);
			}
			else if (biriyani_menu[4][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Handi_biryani_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(14);
			}
			else if (biriyani_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Chicken_biryani_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(10);
				ingre_tick(10);
			}
			else if (biriyani_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Chicken_biryani_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(10);
				ingre_tick(10);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (biriyani_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(10);
			}
			else if (biriyani_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(10);
			}
			else if (biriyani_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(10);
			}
			else if (biriyani_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Kacchi_biryani_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(11);
				ingre_tick(11);
			}
			else if (biriyani_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Kacchi_biryani_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(11);
				ingre_tick(11);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (biriyani_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(11);
			}
			else if (biriyani_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(11);
			}
			else if (biriyani_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(11);
			}
			else if (biriyani_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Beef_Tehari_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(12);
				ingre_tick(12);
			}
			else if (biriyani_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Beef_Tehari_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(12);
				ingre_tick(12);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (biriyani_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(12);
			}
			else if (biriyani_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(12);
			}
			else if (biriyani_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(12);
			}
			else if (biriyani_menu[3][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Shahi_beef_biryani_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(13);
				ingre_tick(13);
			}
			else if (biriyani_menu[3][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Shahi_beef_biryani_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(13);
				ingre_tick(13);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (biriyani_menu[3][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\4_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(13);
			}
			else if (biriyani_menu[3][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\4_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(13);
			}
			else if (biriyani_menu[3][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\4_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(13);
			}
			else if (biriyani_menu[4][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Handi_Biryani.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(14);
				ingre_tick(14);
			}
			else if (biriyani_menu[4][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Handi_Biryani.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(14);
				ingre_tick(14);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (biriyani_menu[4][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\5_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(14);
			}
			else if (biriyani_menu[4][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\5_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(14);
			}
			else if (biriyani_menu[4][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Biryani\\5_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(14);
			}
			else
			{
				iShowBMP(0, 0, "pictures\\Biryani\\Biryani_menu.bmp");
			}
		}
	}
}
void bengali()
{
	if (Recipe_sub[0] == 1)
	{
		if (bengali_fix == 0)
		{
			if (bengali_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(0);
				// printf("something\n");
			}
			else if (bengali_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
				// printf("Something else\n");
			}
			else if (bengali_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(2);
			}
			else if (bengali_menu[3][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\4_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(3);
			}
			else if (bengali_menu[4][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\5_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(4);
			}
			else if (bengali_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);

				ingre_tick(0);
			}
			else if (bengali_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
				ingre_tick(0);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (bengali_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
			}
			else if (bengali_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
			}
			else if (bengali_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
			}
			else if (bengali_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
				ingre_tick(1);
			}
			else if (bengali_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
				ingre_tick(1);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (bengali_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
			}
			else if (bengali_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
			}
			else if (bengali_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(1);
			}
			else if (bengali_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(2);
				ingre_tick(2);
			}
			else if (bengali_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(2);
				ingre_tick(2);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (bengali_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(2);
			}
			else if (bengali_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(2);
			}
			else if (bengali_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(2);
			}
			else if (bengali_menu[3][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(3);
				ingre_tick(3);
			}
			else if (bengali_menu[3][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(3);
				ingre_tick(3);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (bengali_menu[3][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\4_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(3);
			}
			else if (bengali_menu[3][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\4_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(3);
			}
			else if (bengali_menu[3][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\4_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(3);
			}
			else if (bengali_menu[4][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\5_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(4);
				ingre_tick(4);
			}
			else if (bengali_menu[4][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\5_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(4);
				ingre_tick(4);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (bengali_menu[4][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\5_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(4);
			}
			else if (bengali_menu[4][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\5_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(4);
			}
			else if (bengali_menu[4][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\Bengali\\5_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(4);
			}
		}
	}
}
void fast()
{
	if (Recipe_sub[6] == 1)
	{
		if (fast_fix == 0)
		{
			if (fast_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(26);
				// printf("something\n");
			}
			else if (fast_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(27);
				// printf("Something else\n");
			}
			else if (fast_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(28);
			}
			else if (fast_menu[3][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\4_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(29);
			}
			else if (fast_menu[4][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\5_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(30);
			}
			else if (fast_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(26);
				ingre_tick(26);
			}
			else if (fast_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(26);
				ingre_tick(26);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (fast_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(26);
			}
			else if (fast_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(26);
			}
			else if (fast_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(26);
			}
			else if (fast_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(27);
				ingre_tick(27);
			}
			else if (fast_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(27);
				ingre_tick(27);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (fast_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(27);
			}
			else if (fast_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(27);
			}
			else if (fast_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(27);
			}
			else if (fast_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(28);
				ingre_tick(28);
			}
			else if (fast_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(28);
				ingre_tick(28);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (fast_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(28);
			}
			else if (fast_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(28);
			}
			else if (fast_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(28);
			}
			else if (fast_menu[3][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(29);
				ingre_tick(29);
			}
			else if (fast_menu[3][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(29);
				ingre_tick(29);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (fast_menu[3][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\4_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(29);
			}
			else if (fast_menu[3][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\4_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(29);
			}
			else if (fast_menu[3][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\4_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(29);
			}
			else if (fast_menu[4][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\5_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(30);
				ingre_tick(30);
			}
			else if (fast_menu[4][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\fast\\5_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(30);
				ingre_tick(30);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (fast_menu[4][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\5_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(30);
			}
			else if (fast_menu[4][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\5_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(30);
			}
			else if (fast_menu[4][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\fast\\5_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(30);
			}
		}
	}
}
void kebab()
{
	if (Recipe_sub[1] == 1)
	{
		if (kebab_fix == 0)
		{
			if (kebab_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(5);
				printf("something\n");
			}
			else if (kebab_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(6);
				// printf("Something else\n");
			}
			else if (kebab_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(7);
			}
			else if (kebab_menu[3][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\4_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(8);
			}
			else if (kebab_menu[4][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\5_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(9);
			}
			else if (kebab_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(5);
				ingre_tick(5);
			}
			else if (kebab_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(5);
				ingre_tick(5);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (kebab_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(5);
			}
			else if (kebab_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(5);
			}
			else if (kebab_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(5);
			}
			else if (kebab_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(6);
				ingre_tick(6);
			}
			else if (kebab_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(6);
				ingre_tick(6);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (kebab_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(6);
			}
			else if (kebab_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(6);
			}
			else if (kebab_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(6);
			}
			else if (kebab_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(7);
				ingre_tick(7);
			}
			else if (kebab_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(7);
				ingre_tick(7);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (kebab_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(7);
			}
			else if (kebab_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(7);
			}
			else if (kebab_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(7);
			}
			else if (kebab_menu[3][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(8);
				ingre_tick(8);
			}
			else if (kebab_menu[3][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(8);
				ingre_tick(8);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (kebab_menu[3][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\4_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(8);
			}
			else if (kebab_menu[3][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\4_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(8);
			}
			else if (kebab_menu[3][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\4_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(8);
			}
			else if (kebab_menu[4][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\5_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(9);
				ingre_tick(9);
			}
			else if (kebab_menu[4][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\kebab\\5_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(9);
				ingre_tick(9);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (kebab_menu[4][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\5_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(9);
			}
			else if (kebab_menu[4][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\5_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(9);
			}
			else if (kebab_menu[4][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\kebab\\5_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(9);
			}
		}
	}
}
void soup()
{
	if (Recipe_sub[5] == 1)
	{
		if (soup_fix == 0)
		{
			if (soup_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(22);
			}
			else if (soup_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(23);
			}
			else if (soup_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(24);
			}
			else if (soup_menu[3][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\4_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(25);
			}
			else if (soup_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(22);
				ingre_tick(22);
			}
			else if (soup_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(22);
				ingre_tick(22);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (soup_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(22);
				fav_draw(22);
			}
			else if (soup_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(22);
			}
			else if (soup_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(22);
			}
			else if (soup_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(23);
				ingre_tick(23);
			}
			else if (soup_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(23);
				ingre_tick(23);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (soup_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(23);
			}
			else if (soup_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(23);
			}
			else if (soup_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(23);
			}
			else if (soup_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(24);
				ingre_tick(24);
			}
			else if (soup_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(24);
				ingre_tick(24);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (soup_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(24);
			}
			else if (soup_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(24);
			}
			else if (soup_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(24);
			}
			else if (soup_menu[3][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(25);
				ingre_tick(25);
			}
			else if (soup_menu[3][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\soup\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(25);
				ingre_tick(25);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (soup_menu[3][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\4_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(25);
			}
			else if (soup_menu[3][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\4_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(25);
			}
			else if (soup_menu[3][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\soup\\4_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(25);
			}
		}
	}
}
void salad()
{
	if (Recipe_sub[3] == 1)
	{
		if (salad_fix == 0)
		{
			if (salad_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(15);
				printf("something\n");
			}
			else if (salad_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(16);
				// printf("Something else\n");
			}
			else if (salad_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(17);
			}
			else if (salad_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\salad\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(15);
				ingre_tick(15);
			}
			else if (salad_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\salad\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(15);
				ingre_tick(15);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (salad_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(15);
			}
			else if (salad_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(15);
			}
			else if (salad_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(15);
			}
			else if (salad_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\salad\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(16);
				ingre_tick(16);
			}
			else if (salad_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\salad\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(16);
				ingre_tick(16);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (salad_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(16);
			}
			else if (salad_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(16);
			}
			else if (salad_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(16);
			}
			else if (salad_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\salad\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(17);
				ingre_tick(17);
			}
			else if (salad_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\salad\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(17);
				ingre_tick(17);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (salad_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(17);
			}
			else if (salad_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(17);
			}
			else if (salad_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\salad\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(17);
			}
		}
	}
}
void dessert()
{
	if (Recipe_sub[7] == 1)
	{
		if (dessert_fix == 0)
		{
			if (dessert_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(31);
				printf("something\n");
			}
			else if (dessert_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(32);
				// printf("Something else\n");
			}
			else if (dessert_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(33);
			}
			else if (dessert_menu[3][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\4_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(34);
			}
			else if (dessert_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(31);
				ingre_tick(32);
			}
			else if (dessert_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(31);
				ingre_tick(32);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (dessert_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(31);
			}
			else if (dessert_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(31);
			}
			else if (dessert_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(31);
			}
			else if (dessert_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(32);
				ingre_tick(33);
			}
			else if (dessert_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(32);
				ingre_tick(33);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (dessert_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(32);
			}
			else if (dessert_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(32);
			}
			else if (dessert_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(32);
			}
			else if (dessert_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(33);
				ingre_tick(34);
			}
			else if (dessert_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(33);
				ingre_tick(34);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (dessert_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(33);
			}
			else if (dessert_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(33);
			}
			else if (dessert_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(33);
			}
			else if (dessert_menu[3][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(34);
				ingre_tick(31);
			}
			else if (dessert_menu[3][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\dessert\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(34);
				ingre_tick(31);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (dessert_menu[3][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\4_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(34);
			}
			else if (dessert_menu[3][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\4_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(34);
			}
			else if (dessert_menu[3][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\dessert\\4_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(34);
			}
		}
	}
}
void achar()
{
	if (Recipe_sub[9] == 1)
	{
		if (achar_fix == 0)
		{
			if (achar_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(38);
				printf("something\n");
			}
			else if (achar_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(39);
				// printf("Something else\n");
			}
			else if (achar_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(40);
			}
			else if (achar_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\achar\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(38);
				ingre_tick(39);
			}
			else if (achar_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\achar\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(38);
				ingre_tick(39);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (achar_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(38);
			}
			else if (achar_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(38);
			}
			else if (achar_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(38);
			}
			else if (achar_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\achar\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(39);
				ingre_tick(38);
			}
			else if (achar_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\achar\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(39);
				ingre_tick(38);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (achar_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(39);
			}
			else if (achar_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(39);
			}
			else if (achar_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(39);
			}
			else if (achar_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\achar\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(40);
				ingre_tick(40);
			}
			else if (achar_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\achar\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(40);
				ingre_tick(40);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (achar_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(40);
			}
			else if (achar_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(40);
			}
			else if (achar_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\achar\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(40);
			}
		}
	}
}
void vegetable()
{
	if (Recipe_sub[4] == 1)
	{
		if (vegetable_fix == 0)
		{
			if (vegetable_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(18);
			}
			else if (vegetable_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(19);
				// printf("Something else\n");
			}
			else if (vegetable_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(20);
			}
			else if (vegetable_menu[3][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\4_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(21);
			}
			else if (vegetable_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(18);
				ingre_tick(18);
			}
			else if (vegetable_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(18);
				ingre_tick(18);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (vegetable_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(18);
			}
			else if (vegetable_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(18);
			}
			else if (vegetable_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(18);
			}
			else if (vegetable_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(19);
				ingre_tick(19);
			}
			else if (vegetable_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(19);
				ingre_tick(19);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (vegetable_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(19);
			}
			else if (vegetable_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_2.bmp", 0);
				fav_draw(19);
			}
			else if (vegetable_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\2_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_2.bmp", 0);
				fav_draw(19);
			}
			else if (vegetable_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(20);
				ingre_tick(20);
			}
			else if (vegetable_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(20);
				ingre_tick(20);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (vegetable_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(20);
			}
			else if (vegetable_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(20);
			}
			else if (vegetable_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(20);
			}
			else if (vegetable_menu[3][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(21);
				ingre_tick(21);
			}
			else if (vegetable_menu[3][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\4_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(21);
				ingre_tick(21);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (vegetable_menu[3][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\4_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(21);
			}
			else if (vegetable_menu[3][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\4_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(21);
			}
			else if (vegetable_menu[3][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\vegetable\\4_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(21);
			}
		}
	}
}
void pitha()
{
	if (Recipe_sub[8] == 1)
	{
		if (pitha_fix == 0)
		{
			if (pitha_menu[0][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(35);
			}
			else if (pitha_menu[1][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(36);
			}
			else if (pitha_menu[2][0] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(37);
			}
			else if (pitha_menu[0][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\pitha\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(35);
				ingre_tick(3);
			}
			else if (pitha_menu[0][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\pitha\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(35);
				ingre_tick(36);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (pitha_menu[0][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\1_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(35);
			}
			else if (pitha_menu[0][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\1_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(35);
			}
			else if (pitha_menu[0][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\1_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(35);
			}
			else if (pitha_menu[1][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\pitha\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(36);
				ingre_tick(37);
			}
			else if (pitha_menu[1][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\pitha\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(36);
				ingre_tick(37);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (pitha_menu[1][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\2_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(36);
			}
			else if (pitha_menu[1][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\2_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(36);
			}
			else if (pitha_menu[1][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\2_pro_3.bmp");
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				fav_draw(36);
			}
			else if (pitha_menu[2][1] == 1 && ingre_flag == 0)
			{
				iShowBMP(0, 0, "pictures\\pitha\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				fav_draw(37);
				ingre_tick(35);
			}
			else if (pitha_menu[2][1] == 1 && ingre_flag > 0)
			{
				iShowBMP(0, 0, "pictures\\pitha\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(37);
				ingre_tick(35);
				iSetColor(0, 0, 0);
				iText(200, 50, "Click to add to grocery list", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (pitha_menu[2][2] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\3_pro_1.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(37);
			}
			else if (pitha_menu[2][3] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\3_pro_2.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(37);
			}
			else if (pitha_menu[2][4] == 1)
			{
				iShowBMP(0, 0, "pictures\\pitha\\3_pro_3.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				fav_draw(37);
			}
		}
	}
}
void tribal()
{
	if (current_page == 7)
	{
		if (tribal_fix == 0)
		{
			if (i_tribal == 1)
			{
				iShowBMP(0, 0, "pictures\\tribal\\1_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
			else if (i_tribal == 4)
			{
				iShowBMP(0, 0, "pictures\\tribal\\2_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
			else if (i_tribal == 7)
			{
				iShowBMP(0, 0, "pictures\\tribal\\3_des.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
			else if (i_tribal == 2)
			{
				iShowBMP(0, 0, "pictures\\tribal\\1_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
			else if (i_tribal == 3)
			{
				iShowBMP(0, 0, "pictures\\tribal\\1_pro.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
			else if (i_tribal == 5)
			{
				iShowBMP(0, 0, "pictures\\tribal\\2_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
			else if (i_tribal == 6)
			{
				iShowBMP(0, 0, "pictures\\tribal\\2_pro.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
			else if (i_tribal == 8)
			{
				iShowBMP(0, 0, "pictures\\tribal\\3_in.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
				iShowBMP2(1120, 0, "pictures\\Jump\\3-removebg-preview.bmp", 0);
			}
			else if (i_tribal == 9)
			{
				iShowBMP(0, 0, "pictures\\tribal\\3_pro.bmp");
				iShowBMP2(0, 0, "pictures\\Jump\\2-removebg-preview.bmp", 0);
				iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
			}
		}
	}
}
void draw_biryani_menu()
{
	if (biryani_fix == 1 && Recipe_sub[2] == 1)
	{
		if (flag_biryani == 0)
		{
			iShowBMP(0, 0, "pictures\\Biryani\\Biryani_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_biryani == 1)
		{
			iShowBMP(0, 0, "pictures\\Biryani\\Biryani_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_biryani == 2)
		{
			iShowBMP(0, 0, "pictures\\Biryani\\Biryani_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_biryani == 3)
		{
			iShowBMP(0, 0, "pictures\\Biryani\\Biryani_menu_4.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_biryani == 4)
		{
			iShowBMP(0, 0, "pictures\\Biryani\\Biryani_menu_5.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_biryani == 5)
		{
			iShowBMP(0, 0, "pictures\\Biryani\\Biryani_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_bengali_menu()
{
	if (bengali_fix == 1 && Recipe_sub[0] == 1)
	{
		if (flag_bengali == 0)
		{
			iShowBMP(0, 0, "pictures\\Bengali\\Bengali_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_bengali == 1)
		{
			iShowBMP(0, 0, "pictures\\Bengali\\Bengali_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_bengali == 2)
		{
			iShowBMP(0, 0, "pictures\\Bengali\\Bengali_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_bengali == 3)
		{
			iShowBMP(0, 0, "pictures\\Bengali\\Bengali_menu_4.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_bengali == 4)
		{
			iShowBMP(0, 0, "pictures\\Bengali\\Bengali_menu_5.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_bengali == 5)
		{
			iShowBMP(0, 0, "pictures\\Bengali\\Bengali_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_fast_menu()
{
	if (fast_fix == 1 && Recipe_sub[6] == 1)
	{
		if (flag_fast == 0)
		{
			iShowBMP(0, 0, "pictures\\fast\\fast_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_fast == 1)
		{
			iShowBMP(0, 0, "pictures\\fast\\fast_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_fast == 2)
		{
			iShowBMP(0, 0, "pictures\\fast\\fast_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_fast == 3)
		{
			iShowBMP(0, 0, "pictures\\fast\\fast_menu_4.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_fast == 4)
		{
			iShowBMP(0, 0, "pictures\\fast\\fast_menu_5.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_fast == 5)
		{
			iShowBMP(0, 0, "pictures\\fast\\fast_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_soup_menu()
{
	if (soup_fix == 1 && Recipe_sub[5] == 1)
	{
		if (flag_soup == 0)
		{
			iShowBMP(0, 0, "pictures\\soup\\soup_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_soup == 1)
		{
			iShowBMP(0, 0, "pictures\\soup\\soup_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_soup == 2)
		{
			iShowBMP(0, 0, "pictures\\soup\\soup_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_soup == 3)
		{
			iShowBMP(0, 0, "pictures\\soup\\soup_menu_4.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_soup == 5)
		{
			iShowBMP(0, 0, "pictures\\soup\\soup_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_vegetable_menu()
{
	if (vegetable_fix == 1 && Recipe_sub[4] == 1)
	{
		if (flag_vegetable == 0)
		{
			iShowBMP(0, 0, "pictures\\vegetable\\vegetable_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_vegetable == 1)
		{
			iShowBMP(0, 0, "pictures\\vegetable\\vegetable_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_vegetable == 2)
		{
			iShowBMP(0, 0, "pictures\\vegetable\\vegetable_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_vegetable == 3)
		{
			iShowBMP(0, 0, "pictures\\vegetable\\vegetable_menu_4.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_vegetable == 5)
		{
			iShowBMP(0, 0, "pictures\\vegetable\\vegetable_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_salad_menu()
{
	if (salad_fix == 1 && Recipe_sub[3] == 1)
	{
		if (flag_salad == 0)
		{
			iShowBMP(0, 0, "pictures\\salad\\salad_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_salad == 1)
		{
			iShowBMP(0, 0, "pictures\\salad\\salad_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_salad == 2)
		{
			iShowBMP(0, 0, "pictures\\salad\\salad_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_salad == 5)
		{
			iShowBMP(0, 0, "pictures\\salad\\salad_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_achar_menu()
{
	if (achar_fix == 1 && Recipe_sub[9] == 1)
	{
		if (flag_achar == 0)
		{
			iShowBMP(0, 0, "pictures\\achar\\achar_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_achar == 1)
		{
			iShowBMP(0, 0, "pictures\\achar\\achar_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_achar == 2)
		{
			iShowBMP(0, 0, "pictures\\achar\\achar_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_achar == 5)
		{
			iShowBMP(0, 0, "pictures\\achar\\achar_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_tribal_menu()
{
	if (tribal_fix == 0 && current_page == 7)
	{
		if (flag_tribal == 0)
		{
			iShowBMP(0, 0, "pictures\\tribal\\tribal_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_tribal == 1)
		{
			iShowBMP(0, 0, "pictures\\tribal\\tribal_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_tribal == 2)
		{
			iShowBMP(0, 0, "pictures\\tribal\\tribal_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_tribal == 5)
		{
			iShowBMP(0, 0, "pictures\\tribal\\tribal_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_kebab_menu()
{
	if (kebab_fix == 1 && Recipe_sub[1] == 1)
	{
		if (flag_kebab == 0)
		{
			iShowBMP(0, 0, "pictures\\kebab\\kebab_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_kebab == 1)
		{
			iShowBMP(0, 0, "pictures\\kebab\\kebab_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_kebab == 2)
		{
			iShowBMP(0, 0, "pictures\\kebab\\kebab_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_kebab == 3)
		{
			iShowBMP(0, 0, "pictures\\kebab\\kebab_menu_4.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_kebab == 4)
		{
			iShowBMP(0, 0, "pictures\\kebab\\kebab_menu_5.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_kebab == 5)
		{
			iShowBMP(0, 0, "pictures\\kebab\\kebab_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_dessert_menu()
{
	if (dessert_fix == 1 && Recipe_sub[7] == 1)
	{
		if (flag_dessert == 0)
		{
			iShowBMP(0, 0, "pictures\\dessert\\dessert_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_dessert == 1)
		{
			iShowBMP(0, 0, "pictures\\dessert\\dessert_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_dessert == 2)
		{
			iShowBMP(0, 0, "pictures\\dessert\\dessert_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_dessert == 3)
		{
			iShowBMP(0, 0, "pictures\\dessert\\dessert_menu_4.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_dessert == 5)
		{
			iShowBMP(0, 0, "pictures\\dessert\\dessert_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void draw_pitha_menu()
{
	if (pitha_fix == 1 && Recipe_sub[8] == 1)
	{
		if (flag_pitha == 0)
		{
			iShowBMP(0, 0, "pictures\\pitha\\pitha_menu_1.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_pitha == 1)
		{
			iShowBMP(0, 0, "pictures\\pitha\\pitha_menu_2.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_pitha == 2)
		{
			iShowBMP(0, 0, "pictures\\pitha\\pitha_menu_3.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
		else if (flag_pitha == 5)
		{
			iShowBMP(0, 0, "pictures\\pitha\\pitha_menu.bmp");
			iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
		}
	}
}
void ingre_hover(int mx, int my)
{
	if (mx > 555 && mx < 610 && my > 610 && my < 660)
	{
		ingre_flag = 610;
	}
	else if (mx > 555 && mx < 610 && my > 555 && my < 605)
	{
		ingre_flag = 555;
	}
	else if (mx > 555 && mx < 610 && my > 500 && my < 550)
	{
		ingre_flag = 500;
	}
	else if (mx > 555 && mx < 610 && my > 445 && my < 495)
	{
		ingre_flag = 445;
	}
	else if (mx > 555 && mx < 610 && my > 390 && my < 440)
	{
		ingre_flag = 390;
	}
	else if (mx > 555 && mx < 610 && my > 335 && my < 385)
	{
		ingre_flag = 335;
	}
	else if (mx > 555 && mx < 610 && my > 280 && my < 330)
	{
		ingre_flag = 280;
	}
	else if (mx > 555 && mx < 610 && my > 225 && my < 275)
	{
		ingre_flag = 225;
	}
	else if (mx > 555 && mx < 610 && my > 170 && my < 220)
	{
		ingre_flag = 170;
	}
	else if (mx > 555 && mx < 610 && my > 115 && my < 165)
	{
		ingre_flag = 115;
	}
	else if (mx > 555 && mx < 610 && my > 65 && my < 110)
	{
		ingre_flag = 65;
	}
	else if (mx > 555 && mx < 610 && my > 5 && my < 55)
	{
		ingre_flag = 5;
	}
	else
	{
		ingre_flag = 0;
	}
}
void ingre_tick(int b)
{
	if (ingre_sup[b][0] == 1)
	{
		iShowBMP2(560, 615, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][1] == 1)
	{
		iShowBMP2(560, 560, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][2] == 1)
	{
		iShowBMP2(560, 505, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][3] == 1)
	{
		iShowBMP2(560, 450, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][4] == 1)
	{
		iShowBMP2(560, 395, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][5] == 1)
	{
		iShowBMP2(560, 340, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][6] == 1)
	{
		iShowBMP2(560, 285, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][7] == 1)
	{
		iShowBMP2(560, 230, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][8] == 1)
	{
		iShowBMP2(560, 175, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][9] == 1)
	{
		iShowBMP2(560, 120, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][10] == 1)
	{
		iShowBMP2(560, 65, "pictures\\Jump\\tick.bmp", 0);
	}
	if (ingre_sup[b][11] == 1)
	{
		iShowBMP2(560, 10, "pictures\\Jump\\tick.bmp", 0);
	}
}
void ingre_click(int mx, int my, int a)
{
	if (mx > 555 && mx < 610 && my > 610 && my < 660)
	{
		if (ingre_sup[a][0] == 0)
		{
			ingre_sup[a][0] = 1;
		}
		else
		{
			ingre_sup[a][0] = 0;
		}
		printf("1.  %d\n", ingre_sup[a][0]);
	}
	else if (mx > 555 && mx < 610 && my > 555 && my < 605)
	{
		if (ingre_sup[a][1] == 0)
		{
			ingre_sup[a][1] = 1;
		}
		else
		{
			ingre_sup[a][1] = 0;
		}
		printf("2.  %d\n", ingre_sup[a][1]);
	}
	else if (mx > 555 && mx < 610 && my > 500 && my < 550)
	{
		if (ingre_sup[a][2] == 0)
		{
			ingre_sup[a][2] = 1;
		}
		else
		{
			ingre_sup[a][2] = 0;
		}
		printf("3.  %d\n", ingre_sup[a][2]);
	}
	else if (mx > 555 && mx < 610 && my > 445 && my < 495)
	{
		if (ingre_sup[a][3] == 0)
		{
			ingre_sup[a][3] = 1;
		}
		else
		{
			ingre_sup[a][3] = 0;
		}
		printf("4.  %d\n", ingre_sup[a][3]);
	}
	else if (mx > 555 && mx < 610 && my > 390 && my < 440)
	{
		if (ingre_sup[a][4] == 0)
		{
			ingre_sup[a][4] = 1;
		}
		else
		{
			ingre_sup[a][4] = 0;
		}
		printf("5.  %d\n", ingre_sup[a][4]);
	}
	else if (mx > 555 && mx < 610 && my > 335 && my < 385)
	{
		if (ingre_sup[a][5] == 0)
		{
			ingre_sup[a][5] = 1;
		}
		else
		{
			ingre_sup[a][5] = 0;
		}
		printf("6.  %d\n", ingre_sup[a][5]);
	}
	else if (mx > 555 && mx < 610 && my > 280 && my < 330)
	{
		if (ingre_sup[a][6] == 0)
		{
			ingre_sup[a][6] = 1;
		}
		else
		{
			ingre_sup[a][6] = 0;
		}
		printf("7.  %d\n", ingre_sup[a][6]);
	}
	else if (mx > 555 && mx < 610 && my > 225 && my < 275)
	{
		if (ingre_sup[a][7] == 0)
		{
			ingre_sup[a][7] = 1;
		}
		else
		{
			ingre_sup[a][7] = 0;
		}
		printf("8.  %d\n", ingre_sup[a][7]);
	}
	else if (mx > 555 && mx < 610 && my > 170 && my < 220)
	{
		if (ingre_sup[a][8] == 0)
		{
			ingre_sup[a][8] = 1;
		}
		else
		{
			ingre_sup[a][8] = 0;
		}
		printf("9.  %d\n", ingre_sup[a][8]);
	}
	else if (mx > 555 && mx < 610 && my > 115 && my < 165)
	{
		if (ingre_sup[a][9] == 0)
		{
			ingre_sup[a][9] = 1;
		}
		else
		{
			ingre_sup[a][9] = 0;
		}
		printf("10.  %d\n", ingre_sup[a][9]);
	}
	else if (mx > 555 && mx < 610 && my > 65 && my < 110)
	{
		if (ingre_sup[a][10] == 0)
		{
			ingre_sup[a][10] = 1;
		}
		else
		{
			ingre_sup[a][10] = 0;
		}
		printf("11.  %d\n", ingre_sup[a][10]);
	}
	else if (mx > 555 && mx < 610 && my > 5 && my < 55)
	{
		if (ingre_sup[a][11] == 0)
		{
			ingre_sup[a][11] = 1;
		}
		else
		{
			ingre_sup[a][11] = 0;
		}
		printf("12.  %d\n", ingre_sup[a][11]);
	}
}
void welcome()
{
	if (welcome_index == 74)
	{
		current_page = 0;
		welcome_index = 75;
	}
	welcome_index++;
	// printf("%d\n",welcome_index);
	// printf("%d\n",current_page);
}
void match_grocery()
{
	int k = 0;
	int count = 0;
	int flag2 = 0;
	for (int i = 0; i < 41 && k < 11; i++)
	{
		for (int j = 0; j < 12 && k < 11; j++)
		{
			if (*(*(ingre_sup + i) + j) == 1)
			{
				flag2 = 1;
				printf("*\n");
				ingre_num[k] = *(*(ingre_list + i) + j);
				k++;
			}
		}
	}
	// ingre_num[k] = '\0';
	// if (flag2 == 0)
	// {
	// 	ingre_num[0] = 0;
	// }
	for (int i = 0; i < 11; i++)
	{
		printf("%d %d\n", i + 1, ingre_num[i]);
	}
}
void print_grocery()
{
	co_ord_x = 420;
	co_ord_y = 570;
	for (int j = 0; ingre_num[j] != 0; j++)
	{
		// printf("%d ", ingre_num[j]);
		if (co_ord_y > 29 && co_ord_y < 675)
		{
			int n = ingre_num[j] - 1;
			iShowBMP(co_ord_x, co_ord_y, ingre_pic[n]);
			co_ord_y -= 130;
		}
		else
		{
			co_ord_y = 570;
			co_ord_x = 780;
			int n = ingre_num[j] - 1;
			iShowBMP(co_ord_x, co_ord_y, ingre_pic[n]);
			co_ord_y -= 130;
		}
	}
}
void ifab()
{
	co_ord_x = 50;
	co_ord_y = 400;
	for (int j = 0; fav_num[j] != 0; j++)
	{
		// printf("%d ", ingre_num[j]);
		if (co_ord_y > 0 && co_ord_y < 600)
		{
			int n = fav_num[j];
			iShowBMP(co_ord_x, co_ord_y, recipe_pic[n]);
			co_ord_y -= 180;
		}
		else
		{
			co_ord_y = 400;
			co_ord_x = 340;
			int n = ingre_num[j];
			iShowBMP(co_ord_x, co_ord_y, recipe_pic[n]);
			co_ord_y -= 180;
		}
	}
}
void fav(int mx, int my, int b)
{
	if (mx > 10 && mx < 80 && my > 600 && my < 670)
	{
		if (fav_sup[b] == 0)
		{
			fav_sup[b] = 1;
		}
		else
		{
			fav_sup[b] = 0;
		}
	}
}
void match_fav()
{
	int k = 0;
	int flag3 = 0;
	for (int j = 0; j < 42 && k < 11; j++)
	{
		if (fav_sup[j] == 1)
		{
			flag3 = 1;
			fav_num[k] = j;
			k++;
		}
	}
	// if (flag3 == 0)
	// {
	// 	fav_num[0] = 0;
	// }
}
void fav_draw(int b)
{
	if (fav_sup[b] == 1)
	{
		iShowBMP2(10, 600, "pictures\\Jump\\Heart_2.bmp", 0);
	}
	else
	{
		iShowBMP2(10, 600, "pictures\\Jump\\Heart_1.bmp", 0);
	}
}
// void accButton()
// {
// 	nlogin = 0;
// 	nacc = 1;
// 	user[0] = '\0';
// 	pass[0] = '\0';
// 	spass[0] = '\0';
// }
void accin()
{
	FILE *fp = fopen("user\\user.txt", "a");
	FILE *fp2 = fopen("user\\pass.txt", "a");
	if (fp == NULL)
		printf("Error");
	fputs(user, fp);
	fputs("\n", fp);
	fputs(pass, fp2);
	fputs("\n", fp2);
	fclose(fp);
	fclose(fp2);
}
void login()
{
	iShowBMP(0, 0, "pictures\\login\\login.bmp");
}
void iTips()
{
	iShowBMP(0, 0, nutrition_facts[l]);
	iShowBMP2(1100, 575, "pictures\\Jump\\return_1.bmp", 0);
}
int check()
{
	FILE *fp = fopen("user\\user.txt", "r");
	FILE *fp2 = fopen("user\\pass.txt", "r");
	if (fp == NULL)
		printf("Error");
	if (fp2 == NULL)
		printf("Error");

	int pos = 0, flag = 0;
	char tempu[20];
	while (!feof(fp))
	{
		fgets(tempu, 20, fp);
		(tempu[strlen(tempu) - 1] == '\n') ? (tempu[strlen(tempu) - 1] = '\0') : 1;

		if (strcmp(tempu, user) == 0)
		{
			flag = 1;
			break;
		}
		pos++;
	}
	if (flag == 0)
		return auth = 0;
	for (int i = 0; i < pos; i++)
		fgets(tempu, 20, fp2);
	fgets(tempu, 20, fp2);
	(tempu[strlen(tempu) - 1] == '\n') ? (tempu[strlen(tempu) - 1] = '\0') : 1;
	if (strcmp(tempu, pass) == 0)
	{
		fileout_match();
		fileout_fav();
		return auth = 1;
	}
	else
		return auth = 2;
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (nuser == 1)
	{
		if (key == '\r')
		{
			key = '\0';
			npass = 1;
			nuser = 0;
		}
		else if (key == '\b')
		{
			if (iu >= 0)
			{
				user[iu - 1] = '\0';
				iu--;
			}
		}
		else if (iu < 20)
		{
			user[iu] = key;
			user[iu + 1] = '\0';
			iu++;
		}
	}
	if (npass == 1)
	{
		if (key == '\r')
		{
			nuser = 0;
			npass = 0;
		}
		else if (key == '\b')
		{
			if (ip >= 0)
			{
				pass[ip - 1] = '\0';
				spass[ip - 1] = '\0';
				ip--;
			}
		}
		else if (ip < 20 && key != '\0')
		{
			pass[ip] = key;
			pass[ip + 1] = '\0';
			spass[ip] = '*';
			spass[ip + 1] = '\0';
			ip++;
		}
	}
	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
		current_page = 1;
		submenu_page = 0;
		welcome_index = 75;
	}
	// if (key == GLUT_KEY_LEFT)
	// {
	// 	current_page--;
	// }
	// place your codes for other keys here
}

int main()
{
	// place your own initialization codes here.
	if (sound == 1)
	{
		PlaySound("pictures\\Journey_chosic.com_.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iSetTimer(40, welcome);
	printf("%d\n", biryani_index);
	for (int i = 0; i < 42; i++)
	{
		printf("%d ", i + 1);
		for (int j = 0; j < 12; j++)
		{
			printf("%d ", ingre_sup[i][j]);
		}
		printf("\n");
	}
	iInitialize(1200, 675, "Recipe Book");
	return 0;
}
