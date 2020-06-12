//
// Created by Dany Jacob on 23/5/20.
//

#include "IntPtr.h"

Integer * IntPtr::operator->() {
    return m_p;
}

Integer & IntPtr::operator*() {
    return *m_p;
}
