nama = input("Masukkan nama siswa: ")
total = 0
bulan = 0
target = 1800000

while total < target:
    bulan += 1
    while True:
        tabungan = int(input(f"Masukkan tabungan bulan ke-{bulan}: "))
        if tabungan < 200000:
            print("Dana tabungan terlalu kecil")
        elif tabungan > 300000:
            print("Dana terlalu besar")
        else:
            break
    total += tabungan

print("\nNama siswa:", nama)
print("Jumlah bulan:", bulan)

if total == target:
    print("Dana cukup")
else:
    kelebihan = total - target
    print(f"Dana berlebih, kelebihan dana sebesar Rp{kelebihan}")