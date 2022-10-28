class Dsu
{
public:

    vi parent;
    vi siz;

    Dsu(int n)
    {
        n += 5;
        parent.resize(n);
        siz.resize(n);

        For(i, 0, n)
        {
            parent[i] = i;
            siz[i] = 1;

        }

    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;

        return parent[v] = find_set(parent[v]);

    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if (a != b)
        {
            if (siz[a] < siz[b])
                swap(a, b);

            parent[b] = a;
            siz[a] += siz[b];

        }

    }

};
