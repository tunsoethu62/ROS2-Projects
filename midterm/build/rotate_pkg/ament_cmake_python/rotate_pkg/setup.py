from setuptools import find_packages
from setuptools import setup

setup(
    name='rotate_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('rotate_pkg', 'rotate_pkg.*')),
)
