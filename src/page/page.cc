#include "page.h"

namespace Neru {

    // constructors
    Page::Page() : _data(new uint8_t[PAGE_SIZE]) {
        // not necessary
        std::fill_n(_data.get(), PAGE_SIZE, 0);
    }

    // tools
    Page &Page::read(uint8_t *dst, size_t size, size_t offset) {
        if (size + offset > PAGE_SIZE)
            throw std::runtime_error("Page: Out of range!");
        std::copy_n(_data.get() + offset, size, dst);
        return *this;
    }
    Page &Page::write(const uint8_t *src, size_t size, size_t offset) {
        if (size + offset > PAGE_SIZE)
            throw std::runtime_error("Page: Out of range!");
        std::copy_n(src, size, _data.get() + offset);
        return *this;
    }
    char *Page::raw() const { return (char *) _data.get(); }

}// namespace Neru