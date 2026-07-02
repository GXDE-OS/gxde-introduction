#!/bin/bash
cd `dirname $0`
/usr/lib/qt6/bin/lupdate -recursive . -ts translations/gxde-introduction_*.ts
