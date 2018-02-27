//
// Created by kiva on 2018/2/25.
//
#pragma once

#include <unordered_map>
#include <kivm/kivm.h>
#include <kivm/classFile.h>
#include <kivm/classLoader.h>

namespace kivm {
    enum ClassType {
        INSTANCE_CLASS,
        OBJECT_ARRAY_CLASS,
        TYPE_ARRAY_CLASS,
    };

    enum oopType {
        INSTANCE_OOP,
        PRIMITIVE_OOP,
        OBJECT_ARRAY_OOP,
        TYPE_ARRAY_OOP,
    };

    enum ClassState {
        allocated,
        loaded,
        linked,
        being_initialized,
        fully_initialized,
        initialization_error,
    };

    class Klass {
    private:
        ClassState _state;
        u2 _access_flag;

    protected:
        String _name;
        ClassType _type;

        Klass *_super_class;

    public:
        ClassState get_state() const {
            return _state;
        }

        void set_state(ClassState _state) {
            this->_state = _state;
        }

        u2 get_access_flag() const {
            return _access_flag;
        }

        void set_access_flag(u2 _access_flag) {
            Klass::_access_flag = _access_flag;
        }

        const String &get_name() const {
            return _name;
        }

        void set_name(const String &_name) {
            this->_name = _name;
        }

        ClassType get_type() const {
            return _type;
        }

        void set_type(ClassType _type) {
            this->_type = _type;
        }

        Klass *get_super_class() const {
            return _super_class;
        }

        void set_super_class(Klass *_super_class) {
            this->_super_class = _super_class;
        }

    public:
        Klass();

        virtual ~Klass() = default;
    };
}

