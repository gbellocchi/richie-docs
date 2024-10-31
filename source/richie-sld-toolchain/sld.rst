===================
System-level design
===================
.. _richie_toolchain_sld:

The :smallcap:`Richie toolchain` facilitates three SLD phases concerning the assembling of accelerator-rich HeSoCs:

#. :bolditalic:`Accelerator design`;
#. :bolditalic:`System integration`;
#. :bolditalic:`System optimization`.

------------------
Accelerator design
------------------
.. _richie_toolchain_sld_acc_design:

This phase produces the accelerator datapaths. The :smallcap:`Richie toolchain` supports various design flows to
accommodate a wide range of users and application needs, including:

* High-level synthesis:

  * `AMD-Xilinx Vitis HLS <https://www.xilinx.com/products/design-tools/vitis/vitis-hls.html>`_
  * `Coarse-Grain Reconfigurable (CGR) Hardware Accelerators <https://mdc-suite.github.io/>`_

* Manual RTL design:

  * `HWPE-based Accelerators <https://hwpe-doc.readthedocs.io/en/latest/github.html>`_

The IP interface is expected to attain the following requirements:

* Adopt a *streaming-based interface* for data communication, e.g. the AMBA® 4 AXI4-Stream Protocol.
* Adopt *simple data ports* or wires for control parameters, thus with no associated I/O protocol and handshaking signal.

------------------
System integration
------------------
.. _richie_toolchain_sld_integration:

This phase generates the accelerator interfaces which facilitate the integration inside the accelerator-rich HeSoC.
These include HW interfaces for data communication and control, as well as SW drivers (API, runtime, HAL).
The user is asked to provide an *accelerator specification file* describing the characteristics of the accelerator
interface, as shown in the example below:

.. code-block:: python

    class accelerator_specs:

		def engine(self):
			self.name = Accelerator datapath
			self.flow = HLS, RTL
			self.protocol = HWPE
			return self

		def streamer(self):
			self.inputs = [[Name, DataType], ...]
			self.outputs = [[Name, DataType], ...]
			return self

		def controller(self):
			self.regs = [[Name, DataType], ...]
			return self

Specifications are collected in the accelerator library (:code:`src/accelerators/`), including the following sections:

* :code:`specs/`: This location contains the accelerator specification file :code:`accelerator_specs.py`, which
  embodies the required information to specialize the HW/SW interface between the application-specific accelerators
  and the outer platform.

-------------------
System optimization
-------------------
.. _richie_toolchain_sld_optimization:

This phase performs the specialization of the platform parts to meet the requirements of the integrated workload.
The outcome consists of a specialized and optimized *accelerator-rich HeSoC*.
Similarly, this phase mandates a *platform specification file* with the HeSoC characteristics,

.. code-block:: python

    class platform_specs:

            def hesoc(self):
                self.name = Accelerator-Rich HeSoC
                self.target = FPGA fabric
                self.l2_mem = [Number of ports, Size]
                return self

            def cluster_0(self):
                self.acc = [Accelerator name, ...]
                self.proxy = [IP, Number of cores, ...]
                self.dma = [IP, Job queue size, ...]
                self.l1_mem = [Number of ports, Size]
                return self

            ...

            def cluster_N(self)
                ...

Specifications are collected in the platform library (:code:`src/platforms/`), including the following sections:

* :code:`specs/`: This location contains the platform specification file :code:`platform_specs.py`, which guides the
  :smallcap:`Richie toolchain` on how to specialize the accelerator-rich HeSoC.
