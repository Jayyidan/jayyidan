#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int jumlah_data;
    cout << " " << endl;
    cout << "Masukkan jumlah pasangan data: ";
    cin >> jumlah_data;

    int variabel_x[jumlah_data], variabel_y[jumlah_data];
    for (int i = 0; i < jumlah_data; i++)
    {
        bool valid = false;
        while (!valid)
        {
            cout << "Masukkan nilai variabel_x pasangan ke " << i + 1 << ": ";
            cin >> variabel_x[i];
            if (variabel_x[i] >= 0)
            {
                valid = true;
            }
            else
            {
                cout << "Nilai variabel_x tidak valid. Masukkan nilai yang lebih dari atau sama dengan 0: ";
            }
        }
        valid = false;
        while (!valid)
        {
            cout << "Masukkan nilai variabel_y pasangan ke-" << i + 1 << ": ";
            cin >> variabel_y[i];
            if (variabel_y[i] >= 0)
            {
                valid = true;
            }
            else
            {
                cout << "Nilai variabel_y tidak valid. Masukkan nilai yang lebih dari atau sama dengan 0: ";
            }
        }
    }

    float sum_xy = 0, sum_x = 0, sum_y = 0, sum_x2 = 0, sum_y2 = 0;
    for (int i = 0; i < jumlah_data; i++)
    {
        sum_xy += variabel_x[i] * variabel_y[i];
        sum_x += variabel_x[i];
        sum_y += variabel_y[i];
        sum_x2 += variabel_x[i] * variabel_x[i];
        sum_y2 += variabel_y[i] * variabel_y[i];
    }

    float r = (sum_xy - (sum_x * sum_y) / jumlah_data) / sqrt((sum_x2 - (sum_x * sum_x) / jumlah_data) * (sum_y2 - (sum_y * sum_y) / jumlah_data));

    if (r >= -1 && r <= 1)
    {
        cout << "Nilai korelasi r: " << r << endl;
    }
    else
    {
        cout << "Nilai korelasi tidak valid" << endl;
    }
    float r_square = r * r;
    float determinasi = r_square * 100;
    if (determinasi >= 0 && determinasi <= 100)
    {
        cout << "Nilai koefisien determinasi : " << determinasi << "%" << endl;
    }
    else
    {
        cout << "Nilai koefisien determinasi tidak valid" << endl;
    }
    if (r > 0)
    {
        cout << "Hubungan antara variable x dan y adalah positif, dimana jika nilai x bertambah, maka nilai Y akan meningkat, dan juga sebaliknya" << endl;
    }
    else if (r < 0)
    {
        cout << "Hubungan antara variable x dan y adalah negatif, dimana jika nilai x bertambah, maka nilai Y akan menurun, dan juga sebaliknya" << endl;
    }
    else
    {
        cout << "Tidak ada Hubungan antara variable x dan y " << endl;
    }
    return 0;
}
