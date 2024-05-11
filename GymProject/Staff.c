#include "Staff.h"


void imprime_staff(staff_t* staff) {
	printf("INFORMACAO DO FUNCIONARIO COM O ID %d\nNome: %s\nTelefone: %d\nOrdenado: %d\nPassword: %s\n\n",
			staff->id, staff->nome, staff->telefone, staff->ordenado,staff->password);
}



void inicializar_staff(staff_t* staff) {
	staff->nome[0] = '\0';
	staff->telefone = 0;
	staff->ordenado = 0;
	staff->password[0] = '\0';
	staff->id = 0;
}

staff_t* criar_staff(void) {
	staff_t* staff = (staff_t*)malloc(sizeof(staff_t));
	inicializar_staff(staff);

	return staff;
}

void apagar_staff(staff_t* staff) {
	free(staff);
}

staff_t* ler_staff(FILE* fp) {
	staff_t* funcionario = criar_staff();
	if (!fread(funcionario, sizeof(staff_t), 1, fp)) {
		apagar_staff(funcionario);
		funcionario = NULL;
	}
	return funcionario;
}

int escrever_staff(staff_t* funcionario, FILE* fp) {
	return fwrite(funcionario, sizeof(staff_t), 1, fp);
}

