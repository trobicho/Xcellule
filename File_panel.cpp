/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_panel.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:23:34 by trobicho          #+#    #+#             */
/*   Updated: 2019/09/11 20:04:42 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File_panel.h"
#include <QDebug>

File_panel::File_panel()
{
	QSize	availableSize;

	//m_fs_model.setRootPath("/Volumes/Storage/goinfre/trobicho/jslife");
	m_fs_model.setRootPath("/home/tom/Xcellule2D_N/preconfig/");
	setModel(&m_fs_model);
	setRootIndex(m_fs_model.index(m_fs_model.rootPath()));
	setAnimated(false);
	setIndentation(20);
	setSortingEnabled(true);
	availableSize = QApplication::desktop()->availableGeometry(this).size();
	resize(availableSize / 2);
	setColumnWidth(0, this->width() / 3);

	setWindowTitle(QObject::tr("Dir View"));
}

const char	*File_panel::index_to_char(const QModelIndex &index)
{
	QString mPath =	m_fs_model.fileInfo(index).absoluteFilePath();
	return (qPrintable(mPath));
}
