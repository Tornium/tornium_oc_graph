{ lib, python3Packages, pkgs, src, ...}:

python3Packages.buildPythonPackage {
  pname = "tornium_oc_graph";
  version = "0.1.2-dev";
  pyproject = true;

  src = src;

  buildInputs =  [ python3Packages.scikit-build-core ];
  nativeBuildInputs = [
    python3Packages.scikit-build-core
    pkgs.cmake
    pkgs.ninja
  ];

  build-system = with python3Packages; [ scikit-build-core ];
  cmakeDir = "c_src";

  propagatedBuildInputs = [];
  pythonImportCheck = [ "tornium_oc_graph" ];

  meta = with lib; {
    description = "Tornium OC scenario graphs";
    license = licenses.asl20;
  };
}
