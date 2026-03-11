{ lib, python3Packages, pkgs, src, ...}:

python3Packages.buildPythonPackage {
  pname = "tornium_oc_graph";
  version = "0.1.2-dev";
  pyproject = true;

  src = builtins.path{
    path = "${src}";
    name = "tornium_oc_graph";
  };

  nativeBuildInputs = [
    python3Packages.scikit-build-core
    pkgs.cmake
    pkgs.ninja
  ];

  build-system = with python3Packages; [ scikit-build-core ];
  CMAKE_SOURCE_DIR = "c_src";
  CMAKE_ARGS = "-DBUILD_ELIXIR_NIF=OFF -DBUILD_PYTHON=ON";

  propagatedBuildInputs = [];
  pythonImportCheck = [ "tornium_oc_graph" ];

  meta = with lib; {
    description = "Tornium OC scenario graphs";
    license = licenses.asl20;
  };
}
