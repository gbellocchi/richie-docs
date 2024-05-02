# Richie Documentation
The documentation is available [here](https://readthedocs.org/projects/richie-docs/).

## Integration within the Richie Framework
To succesfully build the documentation, this repository should be integrated at the root of the *Richie framework*.
Indeed, many text documents are included from sub-repositories belonging to this ecosystem.

## Dependencies

### Create a Python Virtual Environment
Initialize and install the environment:
```
make py-env-init
source richie-docs-py-venv/bin/activate
make py-env-install
```

### Git Submodules
```
git submodule update --init --recursive
```

## Build the documentation
```
make html
```

## Preview the documentation
The built HTML files (under `build/html/`) can be previewed in the following ways:

1. Open the files with a web browser, e.g., with Firefox run `make open` or `firefox build/html/index.html`;
2. If using Visual Studio Code, then install a local workspace extension, e.g., [Live Preview](https://marketplace.visualstudio.com/items?itemName=ms-vscode.live-server).

## Publications
If you use Richie in your work, you can cite us:

<details>
<summary><b>Richie: A Framework for Agile Design and Exploration of RISC-V-based Accelerator-Rich Heterogeneous SoCs</b></summary>
<p>
  
  ```
  TBD
  ```

</p>
</details>

<details>
<summary><b>A RISC-V-based FPGA overlay to simplify embedded accelerator deployment</b></summary>
<p>

  ```
  @inproceedings{bellocchi2021risc,
    title={A risc-v-based fpga overlay to simplify embedded accelerator deployment},
    author={Bellocchi, Gianluca and Capotondi, Alessandro and Conti, Francesco and Marongiu, Andrea},
    booktitle={2021 24th Euromicro Conference on Digital System Design (DSD)},
    pages={9--17},
    year={2021},
    organization={IEEE}
  }
  ```

</p>
</details>

## Kudos
The repository structure is inspirated and based on *pulp-platform/hwpe-doc*.