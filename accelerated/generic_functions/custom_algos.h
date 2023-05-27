#ifndef CUSTOM_ALGOS_H
#define CUSTOM_ALGOS_H

// The standard library defines five categories of iterators:
// Input iterator: Sequential access in one direction, input only
// Output iterator: Sequential access in one direction, output only
// Forward iterator: Sequential access in one direction, input and output
// Bidirectional iterator: Sequential access in both directions, input and output
// Random-access iterator: Efficient access to any element, input and output

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
    template <class In, class Pred>
    In find_if(In b, In e, Pred p)
    {
        while (b != e)
        {
            if (p(*b))
                return b;
            ++b;
        }
        return e;
    }

    // copy(b, e, d)
    template <class In, class Out>
    Out copy(In b, In e, Out d)
    {
        while (b != e)
        {
            *d = *b;
            ++b;
            ++d;
        }
        return d;
    }

    // remove_copy(b, e, d, t)
    template <class In, class Out, class T>
    Out remove_copy(In b, In e, Out d, const T &t)
    {
        while (b != e)
        {
            if (*b != t)
            {
                *d = *b;
                ++d;
            }
            ++b;
        }
        return d;
    }

    // remove_copy_if(b, e, d, p)
    template <class In, class Out, class Pred>
    Out remove_copy_if(In b, In e, Out d, Pred p)
    {
        while (b != e)
        {
            if (!p(*b))
            {
                *d = *b;
                ++d;
            }
            ++b;
        }
        return d;
    }

    // remove(b, e, t)
    template <class For, class T>
    For remove(For b, For e, const T &t)
    {
        For i = b;
        while (i != e)
        {
            if (*i != t)
            {
                *b = *i;
                ++b;
            }
            ++i;
        }
        return b;
    }

    // transform(b, e, d, f)
    template <class In, class Out, class Func>
    Out transform(In b, In e, Out d, Func f)
    {
        while (b != e)
        {
            *d = f(*b);
            ++b;
            ++d;
        }
        return d;
    }

    // partition(b, e, p)
    template <class For, class Pred>
    For partition(For b, For e, Pred p)
    {
        For i = b;
        while (i != e)
        {
            if (p(*i))
            {
                std::swap(*b, *i);
                ++b;
            }
            ++i;
        }
        return b;
    }

    // accumulate(b, e, t)
    template <class In, class T>
    T accumulate(In b, In e, T t)
    {
        while (b != e)
        {
            t += *b;
            ++b;
        }
        return t;
    }

    template <class In, class T, class BinOp>
    T accumulate(In b, In e, T t, BinOp op)
    {
        while (b != e)
        {
            t = op(t, *b);
            ++b;
        }
        return t;
    }

}

#endif // CUSTOM_ALGOS_H