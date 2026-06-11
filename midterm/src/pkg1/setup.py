from setuptools import find_packages, setup

package_name = 'pkg1'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='soethutun',
    maintainer_email='soethutun@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "circle_publisher = pkg1.circle_publisher:main",
            "odom_logger= pkg1.odom_logger: main",
            "square_service_server = pkg1.server: main",
            "square_service_client = pkg1.client: main",
            "rotate_action_server = pkg1.action_server: main",
            "rotate_action_client = pkg1.action_client: main"
        ],
    },
)
