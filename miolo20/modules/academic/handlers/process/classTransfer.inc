<?php
/**
 * <--- Copyright 2005-2010 de Solis - Cooperativa de Solu��es Livres Ltda.
 * 
 * Este arquivo � parte do programa Sagu.
 * 
 * O Sagu � um software livre; voc� pode redistribu�-lo e/ou modific�-lo
 * dentro dos termos da Licen�a P�blica Geral GNU como publicada pela Funda��o
 * do Software Livre (FSF); na vers�o 2 da Licen�a.
 * 
 * Este programa � distribu�do na esperan�a que possa ser �til, mas SEM
 * NENHUMA GARANTIA; sem uma garantia impl�cita de ADEQUA��O a qualquer MERCADO
 * ou APLICA��O EM PARTICULAR. Veja a Licen�a P�blica Geral GNU/GPL em
 * portugu�s para maiores detalhes.
 * 
 * Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU, sob o t�tulo
 * "LICENCA.txt", junto com este programa, se n�o, acesse o Portal do Software
 * P�blico Brasileiro no endere�o www.softwarepublico.gov.br ou escreva para a
 * Funda��o do Software Livre (FSF) Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA --->
 * 
 * Link de acesso ao formul�rio para transfer�ncia de turma.
 *
 * @author Rodrigo Strate Foga�a [rodrigo@solis.coop.br]
 *
 * @version $Id$
 *
 * \b Maintainers: \n
 * Rodrigo Strate Foga�a [rodrigo@solis.coop.br]
 * 
 * @since
 * Class created on 25/01/2012
 *
 * \b Organization: \n
 * SOLIS - Cooperativa de Solucoes Livres \n
 * The SAGU Development Team
 *
 * \b Copyright: \n
 * Copyright (c) 2005-2007 SOLIS - Cooperativa de Solucoes Livres \n
 * Copyright (c) 2005-2007 UNIVATES - Centro Universitario \n
 *
 * \b License: \n
 * Licensed under GPLv2 (for further details read the COPYING file or http://www.gnu.org/licenses/gpl.html )
 *
 * \b History: \n
 * See: http://sagu.solis.coop.br
 *
 */
$module = MIOLO::getCurrentModule();
$action = 'main:process:classTransfer';
$title = _M('Transfer�ncia de turma', $module);
$form = 'FrmClassTransfer';
SAGU::handle($module, $action, $title, $form, $form);
?>