#include <stdio.h>

int main(){
    FILE *inputFile, *outputFile;
    int nim, nilai, sumMahasiswa = 0, sumNilai = 0;
    inputFile = fopen("datanilai.txt", "r");
    
    if (inputFile == NULL){
        perror("Gagal membuka file datanilai.txt");
        return 1;}
    
    while (fscanf(inputFile, "%d %d", &nim, &nilai)== 2)
    {
        if (nim == 99999999 && nilai == -1) break;
        sumMahasiswa++;
        sumNilai = sumNilai + nilai;
        
    }
    fclose(inputFile);

    float avgNilai = (sumMahasiswa > 0) ? (float)sumNilai/sumMahasiswa: 0.0;
    outputFile = fopen("hasilnilai.txt", "w");
    if (outputFile == NULL)
    {
        perror("Gagal membuka file output.txt");
        return 1;
    }
    
    fprintf(outputFile, "Jumlah mahasiswa : %d\n", sumMahasiswa);
    fprintf(outputFile, "Rata-rata mahasiswa: %0.2f\n", avgNilai);
    fclose(outputFile);
}