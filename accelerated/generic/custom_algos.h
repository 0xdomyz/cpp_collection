#ifndef CUSTOM_ALGOS_H
#define CUSTOM_ALGOS_H

// make a namespace for our custom algorithms
namespace custom_algos
{

    // equal(b, e, d)
    template <class In, class In2>
    bool equal(In b, In e, In2 b2)
    {
        while (b != e)
        {
            if (*b != *b2)
                return false;
            ++b;
            ++b2;
        }
        return true;
    }

    // search(b, e, b2, e2)
    template <class In, class In2>
    In search(In b, In e, In2 b2, In2 e2)
    {
        while (b != e)
        {
            In tmp = b;
            In2 tmp2 = b2;
            while (*tmp == *tmp2)
            {
                ++tmp;
                ++tmp2;
                if (tmp2 == e2)
                    return b;
                if (tmp == e)
                    return e;
            }
            ++b;
        }
        return e;
    }

    // find(b, e, t)
    template <class In, class T>
    In find(In b, In e, const T &t)
    {
        while (b != e)
        {
            if (*b == t)
                return b;
            ++b;
        }
        return e;
    }

    // find_if(b, e, p)
    // copy(b, e, d)
    // remove_copy(b, e, d, t)
    // remove_copy_if(b, e, d, p)
    // remove(b, e, t)
    // transform(b, e, d, f)
    // partition(b, e, p)
    // accumulate(b, e, t)

}

#endif // CUSTOM_ALGOS_H