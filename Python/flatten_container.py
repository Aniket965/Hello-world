import collections


def generate_flatten(container, contaianer_types=collections.Sequence):
    container_list = list(container)
    while container_list:
        while container_list and isinstance(
                container_list[0], contaianer_types):
            container_list[0:1] = container_list[0]
        if container_list:
            yield container_list.pop(0)


def test_generate_flatten():
    flatten_container = list(generate_flatten([[1, 2, [3]], 4]))
    assert flatten_container == [1, 2, 3, 4]


if __name__ == '__main__':
  test_generate_flatten()
  
