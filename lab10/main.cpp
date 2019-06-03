#ifndef MATRIX_H
#define MATRIX_H

#   include <cstdio>
#   include <cstdlib>
#   include <memory.h>

    template <typename T, char FMT>
    class Matrix {
        unsigned y, x;
        T** a;
    public:
        Matrix() {
            x = y = 1;
            a = (T**)malloc(sizeof(T*));
            *a = (T*)malloc(sizeof(T));
        }

        Matrix(unsigned _y, unsigned _x) {
            y = _y;
            x = _x;
            a = (T**)malloc(y * sizeof(T*));
            while (_y--)
                a[_y] = (T*)malloc(x * sizeof(T));
        }

        Matrix(const Matrix& m): Matrix(m.y, m.x) {
            memcpy(a, m.a, y * sizeof(T*));
            for (unsigned i = 0; i < y; i++)
                memcpy(a[i], m.a[i], x * sizeof(T));
        }

        ~Matrix() {
            while (y--)
                free(a[y]);
            free(a);
        }

        unsigned Y() const { return y; }
        unsigned X() const { return x; }

        unsigned Y(unsigned _y) {
            a = (T**)realloc(a, _y * sizeof(T*));
            if (y < _y)
                do
                    a[y++] = (T*)malloc(x * sizeof(T));
                while (y != _y);
            else if (y > _y)
                do
                    free(a[y--]);
                while (y != _y);
            return y;
        }

        unsigned X(unsigned _x) {
            for (unsigned i = 0; i < y; i++)
                a[i] = (T*)realloc(a[i], _x * sizeof(T));
            return x = _x;
        }

        T* operator[ ](unsigned y) { return a[y]; }

        void Print(unsigned y0, unsigned x0, unsigned y1, unsigned x1, char o = 5) const {
            char s[5], i = 2;
            s[0] = '%';
            if ((s[1] = o / 10 + '0') - '0') {
                s[2] = o % 10 + '0';
                i = 3;
            } else
                s[1] = o + '0';
            s[i] = FMT;
            s[i + 1] = '\0';
            for (unsigned i = y0, j; i < y1; i++) {
                for (j = x0; j < x1; j++)
                    printf(s, a[i][j]);
                putchar('\n');
            }
        }

        void Print(unsigned y1, unsigned x1, char o = 5) const { Print(0, 0, y1, x1, o); }

        void Print(char o = 5) const { Print(0, 0, Y(), X(), o); }
    };

#endif
