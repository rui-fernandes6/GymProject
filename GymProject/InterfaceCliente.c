#include "InterfaceCliente.h"
#include "LoginPrincipal.h"

void interface_cliente(cliente_t* cliente) {
	int opc = 0;
	do {
		system("CLS");
		printf("1-Editar os meus dados\n"
			"2-Ver planos de treino \n"
			"3-Ver planos alimentares \n"
			"4-Ver os meus dados\n\n"
			"0- Terminar sessao\n");
		scanf("%d", &opc);
		getchar();
		switch (opc)
		{
		case 1:
			interface_editar_cliente_dados(cliente);
			break;
		case 2:
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
		case 3:
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
			break;
		case 4:
			imprime_informacao_cliente(cliente);
			break;
		case 0:
			break;
		default:
			printf("Introduza uma opcao valida!\n\n");
		}
	} while (opc != 0);

}