<?php
/**
 * <--- Copyright 2011-2011 de Facimed - Faculdade de Ci�ncias Biom�tricas de Cacoal.
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
 * Relat�rio por solicita��o
 *
 * @author Bruno Lazaro dos Santos [brunus.ls@gmail.com]
 *
 * @version $Id$
 *
 * \b Maintainers: \n
 * Equipe Solis [sagu2@solis.coop.br]
 *
 * @since
 * Class created on 24/03/2011
 *
 **/

$module = SAGU::getFileModule(__FILE__);
$action = 'main:document:requestReport';
$title = _M('Relat�rio de solicita��es', $module);
$managementForm = 'FrmRequestReport';
$searchForm = '';

SAGU::handle($module, $action, $title, $searchForm, $managementForm, 'FrmRequestReport');
?>