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
 * Basic employee handler.
 * Contains the menus to access person registers
 *
 * @author Alessandro Rodrigues da Cruz [cpd@facimed.edu.br]
 * 
 * \b Maintainers: \n
 * Equipe Solis [sagu2@solis.coop.br]
 * 
 * @since
 * Class created on 17/03/2011
 *
 **/

$function = MIOLO::_REQUEST('function');
$ui = $MIOLO->getUI();

$MIOLO->trace('file:' . $_SERVER['SCRIPT_NAME']);
$navbar->addOption(_M('Assunto', $module), $module, $action);
access::insert('Assunto', $action, 'default-16x16.png');

if ( (strlen($function) == 0) || ($function == 'search') )
{
    $MIOLO->checkAccess('FrmSubject', A_ACCESS, true, true);

    $content = $ui->getForm($module,'FrmSubjectSearch', $data);
    $content->setClose($MIOLO->getActionURL($module,substr($home, 0, strrpos($home, ':'))));
}
else
{
    switch ( $function )
    {
        case 'insert':
            $MIOLO->checkAccess('FrmSubject', A_INSERT, true, true);
        break;
        case 'update':
            if (strlen(MIOLO::_request('event')) > 0 || $_POST['__EVENTTARGETVALUE'] == 'btnSave:click')
            {
                $MIOLO->checkAccess('FrmSubject', A_UPDATE, true, true);
            }
            else
            {
                $MIOLO->checkAccess('FrmSubject', A_ACCESS, true, true);
            }
        break;
        case 'delete':
            $MIOLO->checkAccess('FrmSubject', A_DELETE, true, true);
        break;
    }

    $i=1;
    $steps[$i++] = new SStepInfo('FrmSubject',  _M('Assunto', $module), $module);
    $steps[$i++] = new SStepInfo('FrmSubjectSector',  _M('Encaminhamentos', $module), $module);
    $steps[$i++] = new SStepInfo('FrmRequiredDocument',  _M('Documentos exigidos', $module), $module);
    
    // se tem campos customizados, exibe o passo
    if ( BasCustomField::existeCamposCustomizados() )
    {
        $steps[$i++] = new SStepInfo('FrmInformacoesExtras',  _M('Informa��es extras', $module), $module);
    }

    $content = SStepByStepForm::getCurrentForm($steps);
}

$theme->clearContent();
$theme->insertContent($content);
?>
