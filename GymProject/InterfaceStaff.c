#include "InterfaceStaff.h"
#include "Interface.h"
#include "ListaCliente.h"

void interface_staff(staff_t* funcionario, lista_cliente_t* clientes) {
	cliente_t* cliente=NULL;
	int opc = 0;
	do {
		system("CLS");
		printf("1-Ver planos de treino do cliente \n"
			"2-Ver planos alimentares do cliente \n"
			"3-Editar os dados do cliente\n"
			"0-Terminar sessao\n");
		scanf("%d", &opc);
		getchar();
		switch (opc)
		{
		case 1:
			cliente = interface_pesquisar_cliente(clientes);
			if (cliente != NULL) {
				switch (cliente->frequencia_semanal)
				{
				case UM_DIA_SEMANAL:
					ler_ficheiro("PT_1.txt");
					break;
				case DOIS_DIAS_SEMANAIS:
					ler_ficheiro("PT_2.txt");
					break;
				case TRES_DIAS_SEMANAIS:
					ler_ficheiro("PT_3.txt");
					break;
				case QUATRO_DIAS_SEMANAIS:
					ler_ficheiro("PT_4.txt");
					break;
				case CINCO_DIAS_SEMANAIS:
					ler_ficheiro("PT_5.txt");
					break;
				case SEIS_DIAS_SEMANAIS:
					ler_ficheiro("PT_6.txt");
					break;
				case SETE_DIAS_SEMANAIS:
					ler_ficheiro("PT_7.txt");
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			cliente = interface_pesquisar_cliente(clientes);
			if (cliente != NULL) {
				switch (cliente->objetivo)
				{
				case PERDER_PESO:
					ler_ficheiro("PA_PP.txt");
					break;
				case HIPERTROFIA_MUSCULAR:
					ler_ficheiro("PA_HM.txt");
					break;
				default:
					ler_ficheiro("PA_M.txt");
					break;
				}
			}
			break;
		case 3:
			interface_pesquisar_editar_dados_fisicos_cliente(clientes);
			break;
		case 0:
			break;
		default:
			printf("Introduza uma opcao valida!\n\n");
		}
	} while (opc != 0);
}