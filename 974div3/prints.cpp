#define debug2(x, y) std:: cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define debug3(x, y, z) std:: cout << #x << " = " << x << " " << #y << " = " << y << " " << #z << " = " << z << "\n";

template<typename T>
ostream &operator <<(ostream &stream, const vector<T> &vector) {
    if (vector.size() == 0) {
        stream << "[]";
        return stream;
    }

    stream << "[";
    for (int i = 0; i < vector.size() - 1; i++) {
        stream << vector[i] << ", ";
    }
    stream << vector[vector.size() - 1] << "]";
    return stream;
}

template<typename T>
void print(T *array, size_t length) {
    if (length == 0) {
        cout << "[]";
        return;
    }

    cout << "[";
    for (int i = 0; i < length - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[length - 1] << "]";
}
