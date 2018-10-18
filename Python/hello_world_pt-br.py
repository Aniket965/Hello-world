#!/usr/bin/env python

"""hello_world_pt-br: overly complicated way of printing "Hello World" in pt-BR!

Based on this blog post:
    https://benkurtovic.com/2014/06/01/obfuscating-hello-world.html

This program prints "Ola mundo!" which is the pt-BR equivalent of "Hello World".
Python3 compatibility.
"""
__author__ = "Victor Neves"
__license__ = "MIT"
__maintainer__ = "Victor Neves"
__email__ = "victorneves478@gmail.com"

(lambda _, __, ___, ____, _____, ______, _______, ________:
    getattr(
        __import__(True.__class__.__name__[_] + [].__class__.__name__[__]),
        ().__class__.__eq__.__class__.__name__[:__] +
        ().__iter__().__class__.__name__[_:][_____:________]
    )(
        _, (lambda _, __, ___: _(_, __, ___))(
            lambda _, __, ___:
                bytes([___ % __]) + _(_, __, ___ // __) if ___ else
                (lambda: _).__code__.co_lnotab,
            _ << ________,
            (((_____ << ____) + _) << ((_____ << ____) - ___)) + (((___ << ___)
            - _) << ((((_ << ____) + _) << __))) - (((_____ << ___) - _) <<
            ((_______ << ___) + (_ << _))) + (((_______ << ___) - _) << ((___ <<
            ____) + _)) + (((((_ << ____) - _) << __) - _) << ((_____ << ___) +
            _)) - ((((((_ << ___) + _)) << ___) + _) << ((_ << _____) + _)) -
            (_______ << ((_______ << __) + _)) + (((___ << ____) + _) << ((_ <<
            ____) + _)) - ((((((_ << ___) + _)) << __) + _) << ((_____ << _))) +
            (_____ << ____) - _
        )
    )
)(
    *(lambda _, __, ___: _(_, __, ___))(
        (lambda _, __, ___:
            [__(___[(lambda: _).__code__.co_nlocals])] +
            _(_, __, ___[(lambda _: _).__code__.co_nlocals:]) if ___ else []
        ),
        lambda _: _.__code__.co_argcount,
        (
            lambda _: _,
            lambda _, __: _,
            lambda _, __, ___: _,
            lambda _, __, ___, ____: _,
            lambda _, __, ___, ____, _____: _,
            lambda _, __, ___, ____, _____, ______: _,
            lambda _, __, ___, ____, _____, ______, _______: _,
            lambda _, __, ___, ____, _____, ______, _______, ________: _
        )
    )
)
