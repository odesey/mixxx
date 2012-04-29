/**
* @file controllerpreset.h
* @author Sean Pappalardo spappalardo@mixxx.org
* @date Mon 9 Apr 2012
* @brief Controller preset
*
* This class represents a controller preset, containing the data elements that
* make it up.
*/

#ifndef CONTROLLERPRESET_H
#define CONTROLLERPRESET_H

#include <QtCore>
#include <QSharedPointer>

class ControllerPresetVisitor;

class ControllerPreset {
  public:
    ControllerPreset() {}
    virtual ~ControllerPreset() {}

    /** addScriptFile(QString,QString)
     * Adds an entry to the list of script file names & associated list of function prefixes
     * @param filename Name of the XML file to add
     * @param functionprefix Function prefix to add
     */
    void addScriptFile(QString filename, QString functionprefix) {
        scriptFileNames.append(filename);
        scriptFunctionPrefixes.append(functionprefix);
    }

    inline void setDeviceId(const QString id) {
        m_deviceId = id;
    }

    inline QString deviceId() const {
        return m_deviceId;
    }

    inline void setFilePath(const QString filePath) {
        m_filePath = filePath;
    }

    inline QString filePath() const {
        return m_filePath;
    }

    virtual void accept(ControllerPresetVisitor* visitor) const = 0;
    virtual bool isMappable() const = 0;

    // Data elements
    // TODO(XXX) make private
    QList<QString> scriptFileNames;
    QList<QString> scriptFunctionPrefixes;

  private:
    QString m_deviceId;
    QString m_filePath;
};

typedef QSharedPointer<ControllerPreset> ControllerPresetPointer;

#endif